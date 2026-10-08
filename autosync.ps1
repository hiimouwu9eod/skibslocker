# Watches this folder and auto-commits + pushes every change to GitHub.
# Run: powershell -ExecutionPolicy Bypass -File autosync.ps1
# Stop: kill the powershell process running this script.

$repo = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $repo

function SyncOnce($reason) {
    try {
        Set-Location $repo
        $status = git status --porcelain 2>$null
        if ([string]::IsNullOrWhiteSpace($status)) { return }
        git add -A 2>$null | Out-Null
        $status = git status --porcelain 2>$null
        if ([string]::IsNullOrWhiteSpace($status)) { return }
        $msg = "autosync $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') ($reason)"
        git commit -m $msg 2>$null | Out-Null
        git push origin main 2>$null | Out-Null
        Write-Host "[autosync] pushed: $msg"
    } catch { }
}

# Push current branch upstream if needed, then initial sync.
$branch = (git branch --show-current 2>$null)
if ([string]::IsNullOrWhiteSpace($branch)) { $branch = 'main' }
SyncOnce 'startup'

$watcher = New-Object System.IO.FileSystemWatcher
$watcher.Path = $repo
$watcher.IncludeSubdirectories = $true
$watcher.NotifyFilter = [System.IO.NotifyFilters]::FileName -bor
    [System.IO.NotifyFilters]::LastWrite -bor
    [System.IO.NotifyFilters]::DirectoryName
$watcher.EnableRaisingEvents = $true

$last = [DateTime]::MinValue
$action = {
    $now = Get-Date
    # debounce: max 1 sync per 10 seconds
    if (($now - $script:last).TotalSeconds -lt 10) { return }
    $script:last = $now
    Start-Sleep -Seconds 5  # let editors finish writing
    SyncOnce 'change'
}
$handlers = @(
    Register-ObjectEvent $watcher Created -Action $action,
    Register-ObjectEvent $watcher Changed -Action $action,
    Register-ObjectEvent $watcher Deleted -Action $action,
    Register-ObjectEvent $watcher Renamed -Action $action
)

Write-Host "[autosync] watching $repo (Ctrl+C to stop)"
try {
    while ($true) { Start-Sleep -Seconds 30; SyncOnce 'periodic' }
} finally {
    $handlers | ForEach-Object { Unregister-Event -SourceIdentifier $_.Name -ErrorAction SilentlyContinue }
}
