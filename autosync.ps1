# Watches this folder and auto-commits + pushes every change to GitHub.
# Run: powershell -ExecutionPolicy Bypass -File autosync.ps1
# Stop: kill the powershell process running this script.

$repo = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $repo
$logFile = Join-Path $repo '.autosync.log'

function Log($msg) {
    $line = "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] $msg"
    Write-Host $line
    try { Add-Content -Path $logFile -Value $line -ErrorAction SilentlyContinue } catch { }
}

function SyncOnce($reason) {
    try {
        Set-Location $repo
        $status = git status --porcelain 2>$null
        if ([string]::IsNullOrWhiteSpace($status)) { return }
        # never commit the log itself
        git add -A 2>$null | Out-Null
        git reset -q .autosync.log 2>$null
        $status = git status --porcelain 2>$null
        if ([string]::IsNullOrWhiteSpace($status)) { return }
        $msg = "autosync $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss') ($reason)"
        git commit -m $msg 2>$null | Out-Null
        git push origin main 2>$null | Out-Null
        Log "pushed: $msg"
    } catch { }
}

Log "watching $repo"
SyncOnce 'startup'
while ($true) {
    Start-Sleep -Seconds 15
    SyncOnce 'periodic'
}
