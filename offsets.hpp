#pragma once
/*
/* =============================================================
/*  rbxoffsets — composed offsets
/*  
/*  Roblox Version  : version-cec3ad5889b447cf
/*  Total Offsets   : 1674
/*  Composed At     : 2026-10-06T13:17:18.917Z
/*  
/*  Composed from a verified dump by rbxoffsets and a mirrored
/*  dump from another source. Where both name an offset and disagree,
/*  the mirrored value is served; ours fills only its gaps and zeros.
/*  
/*  verified only 1281   mirrored only 242   agreed 128
/*  disputed 6   repaired 1   unknown 16
/* =============================================================
*/

#include <cstdint>
#include <string>
namespace Offsets {
    inline std::string ClientVersion = "version-cec3ad5889b447cf";

    namespace AccessoryDescription {
         inline constexpr uintptr_t AssetId = 0xb0;
         inline constexpr uintptr_t IsLayered = 0xe8;
         inline constexpr uintptr_t Order = 0xe0;
         inline constexpr uintptr_t Puffiness = 0xe4;
    }

    namespace Accoutrement {
         inline constexpr uintptr_t AttachmentPoint = 0xa8;
    }

    namespace AdPlacement {
         inline constexpr uintptr_t PlacementId = 0x120;
         inline constexpr uintptr_t Visible = 0x12c;
    }

    namespace AdPortal {
         inline constexpr uintptr_t PortalVersion = 0xc8;
    }

    namespace AirController {
         inline constexpr uintptr_t BalanceMaxTorque = 0xdc;
         inline constexpr uintptr_t BalanceSpeed = 0xe0;
         inline constexpr uintptr_t LinearImpulse = 0xd0;
         inline constexpr uintptr_t MaintainAngularMomentum = 0xf0;
         inline constexpr uintptr_t MoveMaxForce = 0xe4;
         inline constexpr uintptr_t TurnMaxTorque = 0xe8;
         inline constexpr uintptr_t TurnSpeedFactor = 0xec;
    }

    namespace AirProperties {
         inline constexpr uintptr_t AirDensity = 0x18;
         inline constexpr uintptr_t GlobalWind = 0x3c;
    }

    namespace AlignOrientation {
         inline constexpr uintptr_t MaxAngularVelocity = 0x194;
         inline constexpr uintptr_t MaxTorque = 0x198;
         inline constexpr uintptr_t PrimaryAxisOnly = 0x1a4;
         inline constexpr uintptr_t ReactionTorqueEnabled = 0x1a5;
         inline constexpr uintptr_t Responsiveness = 0x1a0;
         inline constexpr uintptr_t RigidityEnabled = 0x1a6;
    }

    namespace AlignPosition {
         inline constexpr uintptr_t MaxAxesForce = 0x160;
         inline constexpr uintptr_t MaxForce = 0x180;
         inline constexpr uintptr_t MaxVelocity = 0x184;
         inline constexpr uintptr_t Position = 0x16c;
         inline constexpr uintptr_t Responsiveness = 0x18c;
         inline constexpr uintptr_t RigidityEnabled = 0x192;
    }

    namespace AngularVelocity {
         inline constexpr uintptr_t AngularVelocity = 0x160;
         inline constexpr uintptr_t MaxTorque = 0x16c;
         inline constexpr uintptr_t ReactionTorqueEnabled = 0x174;
    }

    namespace AnimatedImageTrack {
         inline constexpr uintptr_t Duration = 0x80;
         inline constexpr uintptr_t FrameCount = 0x84;
    }

    namespace AnimationClip {
         inline constexpr uintptr_t Guid = 0xb0;
         inline constexpr uintptr_t Loop = 0xbc;
    }

    namespace AnimationConstraint {
         inline constexpr uintptr_t AngularDamping = 0x160;
         inline constexpr uintptr_t EnableSkinning = 0x178;
         inline constexpr uintptr_t IsKinematic = 0x179;
         inline constexpr uintptr_t LinearDamping = 0x168;
         inline constexpr uintptr_t LinearStrength = 0x16c;
         inline constexpr uintptr_t MaxForce = 0x170;
         inline constexpr uintptr_t MaxTorque = 0x174;
    }

    namespace AnimationPlayer {
         inline constexpr uintptr_t AutoPlay = 0x118;
         inline constexpr uintptr_t CurrentFrame = 0x110;
         inline constexpr uintptr_t Enabled = 0x119;
         inline constexpr uintptr_t IsPlaying = 0x11a;
         inline constexpr uintptr_t Loop = 0x11b;
         inline constexpr uintptr_t Speed = 0x114;
         inline constexpr uintptr_t TimePosition = 0x108;
    }

    namespace AnimationStreamTrack {
         inline constexpr uintptr_t WeightTarget = 0xb0;
    }

    namespace AnimationTrack {
         inline constexpr uintptr_t Animation = 0xa8;
         inline constexpr uintptr_t Animator = 0x100;
         inline constexpr uintptr_t IsPlaying = 0xa48;
         inline constexpr uintptr_t Looped = 0xd5;
         inline constexpr uintptr_t Speed = 0xc4;
         inline constexpr uintptr_t TimePosition = 0xc8;
         inline constexpr uintptr_t WeightTarget = 0xd0;
    }

    namespace Animator {
         inline constexpr uintptr_t ActiveAnimations = 0xa80;
         inline constexpr uintptr_t AnimTrackMetadata0 = 0x394;
         inline constexpr uintptr_t AnimTrackMetadata1 = 0x398;
         inline constexpr uintptr_t AnimTrackMetadata10 = 0x39c;
         inline constexpr uintptr_t AnimTrackMetadata11 = 0x3a0;
         inline constexpr uintptr_t AnimTrackMetadata12 = 0x3a4;
         inline constexpr uintptr_t AnimTrackMetadata13 = 0x3a8;
         inline constexpr uintptr_t AnimTrackMetadata14 = 0x3ac;
         inline constexpr uintptr_t AnimTrackMetadata15 = 0x3b0;
         inline constexpr uintptr_t AnimTrackMetadata2 = 0x3b4;
         inline constexpr uintptr_t AnimTrackMetadata3 = 0x3b8;
         inline constexpr uintptr_t AnimTrackMetadata4 = 0x3bc;
         inline constexpr uintptr_t AnimTrackMetadata5 = 0x3c0;
         inline constexpr uintptr_t AnimTrackMetadata6 = 0x3c4;
         inline constexpr uintptr_t AnimTrackMetadata7 = 0x3c8;
         inline constexpr uintptr_t AnimTrackMetadata8 = 0x3cc;
         inline constexpr uintptr_t AnimTrackMetadata9 = 0x3d0;
         inline constexpr uintptr_t AnimTrackPlayState0 = 0xe0;
         inline constexpr uintptr_t AnimTrackPlayState1 = 0xf0;
         inline constexpr uintptr_t AnimTrackPlayState10 = 0x100;
         inline constexpr uintptr_t AnimTrackPlayState11 = 0x110;
         inline constexpr uintptr_t AnimTrackPlayState12 = 0x120;
         inline constexpr uintptr_t AnimTrackPlayState13 = 0x130;
         inline constexpr uintptr_t AnimTrackPlayState14 = 0x140;
         inline constexpr uintptr_t AnimTrackPlayState15 = 0x150;
         inline constexpr uintptr_t AnimTrackPlayState2 = 0x160;
         inline constexpr uintptr_t AnimTrackPlayState3 = 0x170;
         inline constexpr uintptr_t AnimTrackPlayState4 = 0x180;
         inline constexpr uintptr_t AnimTrackPlayState5 = 0x190;
         inline constexpr uintptr_t AnimTrackPlayState6 = 0x1a0;
         inline constexpr uintptr_t AnimTrackPlayState7 = 0x1b0;
         inline constexpr uintptr_t AnimTrackPlayState8 = 0x1c0;
         inline constexpr uintptr_t AnimTrackPlayState9 = 0x1d0;
         inline constexpr uintptr_t AnimTrackWeight0 = 0x1e0;
         inline constexpr uintptr_t AnimTrackWeight1 = 0x1f0;
         inline constexpr uintptr_t AnimTrackWeight10 = 0x200;
         inline constexpr uintptr_t AnimTrackWeight11 = 0x210;
         inline constexpr uintptr_t AnimTrackWeight12 = 0x220;
         inline constexpr uintptr_t AnimTrackWeight13 = 0x230;
         inline constexpr uintptr_t AnimTrackWeight14 = 0x240;
         inline constexpr uintptr_t AnimTrackWeight15 = 0x250;
         inline constexpr uintptr_t AnimTrackWeight2 = 0x260;
         inline constexpr uintptr_t AnimTrackWeight3 = 0x270;
         inline constexpr uintptr_t AnimTrackWeight4 = 0x280;
         inline constexpr uintptr_t AnimTrackWeight5 = 0x290;
         inline constexpr uintptr_t AnimTrackWeight6 = 0x2a0;
         inline constexpr uintptr_t AnimTrackWeight7 = 0x2b0;
         inline constexpr uintptr_t AnimTrackWeight8 = 0x2c0;
         inline constexpr uintptr_t AnimTrackWeight9 = 0x2d0;
         inline constexpr uintptr_t AnimationId0 = 0x2e0;
         inline constexpr uintptr_t AnimationId1 = 0x2e8;
         inline constexpr uintptr_t AnimationId10 = 0x2f0;
         inline constexpr uintptr_t AnimationId11 = 0x2f8;
         inline constexpr uintptr_t AnimationId12 = 0x300;
         inline constexpr uintptr_t AnimationId13 = 0x308;
         inline constexpr uintptr_t AnimationId14 = 0x310;
         inline constexpr uintptr_t AnimationId15 = 0x318;
         inline constexpr uintptr_t AnimationId2 = 0x320;
         inline constexpr uintptr_t AnimationId3 = 0x328;
         inline constexpr uintptr_t AnimationId4 = 0x330;
         inline constexpr uintptr_t AnimationId5 = 0x338;
         inline constexpr uintptr_t AnimationId6 = 0x340;
         inline constexpr uintptr_t AnimationId7 = 0x348;
         inline constexpr uintptr_t AnimationId8 = 0x350;
         inline constexpr uintptr_t AnimationId9 = 0x358;
         inline constexpr uintptr_t PreferLodEnabled = 0x3d4;
         inline constexpr uintptr_t RootMotion = 0x360;
         inline constexpr uintptr_t RootMotionWeight = 0x390;
    }

    namespace ArcHandles {
         inline constexpr uintptr_t MouseButton1UpConnectionCount = 0x118;
         inline constexpr uintptr_t MouseDragConnectionCount = 0x11c;
         inline constexpr uintptr_t MouseEnterConnectionCount = 0x120;
         inline constexpr uintptr_t MouseLeaveConnectionCount = 0x124;
    }

    namespace AssetDeliveryProxy {
         inline constexpr uintptr_t Interface = 0xb8;
         inline constexpr uintptr_t StartServer = 0xdc;
    }

    namespace AssetService {
         inline constexpr uintptr_t AllowInsertFreeAssets = 0xb0;
    }

    namespace Atmosphere {
         inline constexpr uintptr_t Color = 0xa8;
         inline constexpr uintptr_t Decay = 0xb4;
         inline constexpr uintptr_t Density = 0xc0;
         inline constexpr uintptr_t Glare = 0xc4;
         inline constexpr uintptr_t Haze = 0xc8;
         inline constexpr uintptr_t Offset = 0xcc;
    }

    namespace Attachment {
         inline constexpr uintptr_t Axis = 0xa8;
         inline constexpr uintptr_t Position = 0xb4;
         inline constexpr uintptr_t SecondaryAxis = 0xc0;
         inline constexpr uintptr_t Visible = 0xcc;
    }

    namespace AudioChorus {
         inline constexpr uintptr_t Bypass = 0x134;
         inline constexpr uintptr_t Depth = 0x128;
         inline constexpr uintptr_t Rate = 0x130;
    }

    namespace AudioCompressor {
         inline constexpr uintptr_t Attack = 0x128;
         inline constexpr uintptr_t Bypass = 0x13c;
         inline constexpr uintptr_t Ratio = 0x130;
         inline constexpr uintptr_t Release = 0x134;
         inline constexpr uintptr_t Threshold = 0x138;
    }

    namespace AudioDeviceInput {
         inline constexpr uintptr_t Active = 0x168;
         inline constexpr uintptr_t DictationEnabled = 0x169;
         inline constexpr uintptr_t EchoCancellation = 0x16a;
         inline constexpr uintptr_t Muted = 0x16c;
         inline constexpr uintptr_t MutedByLocalUser = 0x16d;
         inline constexpr uintptr_t NoiseSuppression = 0x16e;
         inline constexpr uintptr_t Volume = 0x164;
    }

    namespace AudioDistortion {
         inline constexpr uintptr_t Level = 0x128;
    }

    namespace AudioEcho {
         inline constexpr uintptr_t Bypass = 0x13c;
         inline constexpr uintptr_t DelayTime = 0x128;
         inline constexpr uintptr_t Feedback = 0x130;
         inline constexpr uintptr_t RampTime = 0x134;
         inline constexpr uintptr_t WetLevel = 0x138;
    }

    namespace AudioEmitter {
         inline constexpr uintptr_t AcousticSimulationEnabled = 0x170;
    }

    namespace AudioEqualizer {
         inline constexpr uintptr_t Bypass = 0x13c;
         inline constexpr uintptr_t HighGain = 0x130;
         inline constexpr uintptr_t LowGain = 0x134;
         inline constexpr uintptr_t MidGain = 0x138;
         inline constexpr uintptr_t MidRange = 0x128;
    }

    namespace AudioFader {
         inline constexpr uintptr_t Volume = 0x128;
    }

    namespace AudioFilter {
         inline constexpr uintptr_t Bypass = 0x138;
         inline constexpr uintptr_t Gain = 0x130;
         inline constexpr uintptr_t Q = 0x134;
    }

    namespace AudioFlanger {
         inline constexpr uintptr_t Bypass = 0x134;
         inline constexpr uintptr_t Depth = 0x128;
         inline constexpr uintptr_t Rate = 0x130;
    }

    namespace AudioGate {
         inline constexpr uintptr_t Attack = 0x130;
         inline constexpr uintptr_t Bypass = 0x138;
         inline constexpr uintptr_t Release = 0x134;
         inline constexpr uintptr_t Threshold = 0x128;
    }

    namespace AudioLimiter {
         inline constexpr uintptr_t Bypass = 0x130;
         inline constexpr uintptr_t MaxLevel = 0x128;
    }

    namespace AudioPitchShifter {
         inline constexpr uintptr_t Bypass = 0x130;
         inline constexpr uintptr_t Pitch = 0x128;
    }

    namespace AudioPlayer {
         inline constexpr uintptr_t IsPlaying = 0x162;
         inline constexpr uintptr_t LoopRegion = 0x148;
         inline constexpr uintptr_t Volume = 0x15c;
    }

    namespace AudioRecorder {
         inline constexpr uintptr_t IsRecording = 0x128;
    }

    namespace AudioReverb {
         inline constexpr uintptr_t DecayRatio = 0x128;
         inline constexpr uintptr_t Density = 0x130;
         inline constexpr uintptr_t Diffusion = 0x134;
         inline constexpr uintptr_t DryLevel = 0x138;
         inline constexpr uintptr_t EarlyDelayTime = 0x13c;
         inline constexpr uintptr_t HighCutFrequency = 0x140;
         inline constexpr uintptr_t LateDelayTime = 0x144;
         inline constexpr uintptr_t LowShelfFrequency = 0x148;
         inline constexpr uintptr_t LowShelfGain = 0x14c;
         inline constexpr uintptr_t ReferenceFrequency = 0x150;
         inline constexpr uintptr_t WetLevel = 0x154;
    }

    namespace AudioSearchParams {
         inline constexpr uintptr_t MaxDuration = 0x14c;
         inline constexpr uintptr_t MinDuration = 0x150;
    }

    namespace AudioSpeechToText {
         inline constexpr uintptr_t DictationEnabled = 0x168;
         inline constexpr uintptr_t DisableVoiceDetection = 0x169;
         inline constexpr uintptr_t EnableVolumeCheck = 0x16a;
         inline constexpr uintptr_t VoiceDetected = 0x16c;
         inline constexpr uintptr_t VoiceDetectedOverride = 0x16d;
    }

    namespace AudioTextToSpeech {
         inline constexpr uintptr_t AutoLocalize = 0x180;
         inline constexpr uintptr_t IsPlaying = 0x181;
         inline constexpr uintptr_t Looping = 0x182;
         inline constexpr uintptr_t Pitch = 0x170;
         inline constexpr uintptr_t PlaybackSpeed = 0x174;
         inline constexpr uintptr_t Speed = 0x178;
         inline constexpr uintptr_t Volume = 0x17c;
    }

    namespace AudioTremolo {
         inline constexpr uintptr_t Bypass = 0x140;
         inline constexpr uintptr_t Depth = 0x128;
         inline constexpr uintptr_t Frequency = 0x130;
         inline constexpr uintptr_t Shape = 0x134;
         inline constexpr uintptr_t Skew = 0x138;
         inline constexpr uintptr_t Square = 0x13c;
    }

    namespace AudioWindSynthesizer {
         inline constexpr uintptr_t Enabled = 0x13c;
         inline constexpr uintptr_t Volume = 0x138;
    }

    namespace AuroraScript {
         inline constexpr uintptr_t Priority = 0x12c;
    }

    namespace AuroraScriptObject {
         inline constexpr uintptr_t FrameId = 0xc0;
         inline constexpr uintptr_t LODLevel = 0xc4;
         inline constexpr uintptr_t MaxFrequency = 0xc8;
         inline constexpr uintptr_t PriorFrameInvoked = 0xcc;
    }

    namespace AuroraService {
         inline constexpr uintptr_t BufferFullInputCount = 0xd0;
         inline constexpr uintptr_t InputDropRate = 0xd4;
         inline constexpr uintptr_t OutOfOrderInputCount = 0xd8;
         inline constexpr uintptr_t RollbackOffset = 0xdc;
         inline constexpr uintptr_t TooOldInputCount = 0xe0;
    }

    namespace AvatarAbilityRules {
         inline constexpr uintptr_t EnableClimbing = 0xa4;
         inline constexpr uintptr_t EnableCrouching = 0xa5;
         inline constexpr uintptr_t EnableFallingDown = 0xa6;
         inline constexpr uintptr_t EnableHolding = 0xa8;
         inline constexpr uintptr_t EnableJumping = 0xa9;
    }

    namespace AvatarAccessoryRules {
         inline constexpr uintptr_t CustomBackAccessoryId = 0xa0;
         inline constexpr uintptr_t CustomFaceAccessoryId = 0xa8;
         inline constexpr uintptr_t CustomFrontAccessoryId = 0xb0;
         inline constexpr uintptr_t CustomHairAccessoryId = 0xb8;
         inline constexpr uintptr_t CustomHeadAccessoryEnabled = 0xfc;
         inline constexpr uintptr_t CustomHeadAccessoryId = 0xc0;
         inline constexpr uintptr_t CustomNeckAccessoryId = 0xc8;
         inline constexpr uintptr_t CustomShoulderAccessoryId = 0xd0;
         inline constexpr uintptr_t CustomWaistAccessoryId = 0xd8;
         inline constexpr uintptr_t EnableEmissives = 0x100;
         inline constexpr uintptr_t EnableSound = 0x101;
         inline constexpr uintptr_t EnableVFX = 0x102;
    }

    namespace AvatarAnimationRules {
         inline constexpr uintptr_t CustomClimbAnimationId = 0xa0;
         inline constexpr uintptr_t CustomFallAnimationId = 0xa8;
         inline constexpr uintptr_t CustomIdleAlt1AnimationId = 0xb0;
         inline constexpr uintptr_t CustomIdleAlt2AnimationId = 0xb8;
         inline constexpr uintptr_t CustomIdleAnimationEnabled = 0xfc;
         inline constexpr uintptr_t CustomIdleAnimationId = 0xc0;
         inline constexpr uintptr_t CustomJumpAnimationId = 0xc8;
         inline constexpr uintptr_t CustomRunAnimationId = 0xd0;
         inline constexpr uintptr_t CustomSwimAnimationId = 0xd8;
         inline constexpr uintptr_t CustomSwimIdleAnimationEnabled = 0x100;
         inline constexpr uintptr_t CustomSwimIdleAnimationId = 0xe0;
         inline constexpr uintptr_t CustomWalkAnimationEnabled = 0x101;
         inline constexpr uintptr_t CustomWalkAnimationId = 0xe8;
    }

    namespace AvatarBodyRules {
         inline constexpr uintptr_t CustomBodyBundleId = 0xa0;
         inline constexpr uintptr_t CustomEyebrowEnabled = 0x138;
         inline constexpr uintptr_t CustomEyebrowId = 0xa8;
         inline constexpr uintptr_t CustomEyelashId = 0xb0;
         inline constexpr uintptr_t CustomFaceId = 0xb8;
         inline constexpr uintptr_t CustomHeadId = 0xc0;
         inline constexpr uintptr_t CustomLeftArmId = 0xc8;
         inline constexpr uintptr_t CustomLeftLegId = 0xd0;
         inline constexpr uintptr_t CustomMoodId = 0xd8;
         inline constexpr uintptr_t CustomRightArmId = 0xe0;
         inline constexpr uintptr_t CustomRightLegId = 0xe8;
         inline constexpr uintptr_t CustomTorsoId = 0xf0;
    }

    namespace AvatarClothingRules {
         inline constexpr uintptr_t CustomClassicPantsAccessoryEnabled = 0x114;
         inline constexpr uintptr_t CustomClassicPantsAccessoryId = 0xa0;
         inline constexpr uintptr_t CustomClassicShirtsAccessoryEnabled = 0x115;
         inline constexpr uintptr_t CustomClassicShirtsAccessoryId = 0xa8;
         inline constexpr uintptr_t CustomClassicTShirtsAccessoryEnabled = 0x116;
         inline constexpr uintptr_t CustomClassicTShirtsAccessoryId = 0xb0;
         inline constexpr uintptr_t CustomDressSkirtAccessoryEnabled = 0x117;
         inline constexpr uintptr_t CustomDressSkirtAccessoryId = 0xb8;
         inline constexpr uintptr_t CustomJacketAccessoryEnabled = 0x118;
         inline constexpr uintptr_t CustomJacketAccessoryId = 0xc0;
         inline constexpr uintptr_t CustomLeftShoesAccessoryEnabled = 0x119;
         inline constexpr uintptr_t CustomLeftShoesAccessoryId = 0xc8;
         inline constexpr uintptr_t CustomPantsAccessoryId = 0xd0;
         inline constexpr uintptr_t CustomRightShoesAccessoryId = 0xd8;
         inline constexpr uintptr_t CustomShirtAccessoryId = 0xe0;
         inline constexpr uintptr_t CustomShortsAccessoryId = 0xe8;
         inline constexpr uintptr_t CustomSweaterAccessoryId = 0xf0;
         inline constexpr uintptr_t CustomTShirtAccessoryId = 0xf8;
    }

    namespace AvatarCollisionRules {
         inline constexpr uintptr_t SingleColliderSize = 0xa0;
    }

    namespace AvatarSettings {
         inline constexpr uintptr_t Loaded = 0xd0;
    }

    namespace BallSocketConstraint {
         inline constexpr uintptr_t EnableSkinning = 0x178;
         inline constexpr uintptr_t LimitsEnabled = 0x179;
         inline constexpr uintptr_t MaxFrictionTorque = 0x160;
         inline constexpr uintptr_t Restitution = 0x168;
         inline constexpr uintptr_t TwistLimitsEnabled = 0x17a;
         inline constexpr uintptr_t TwistLowerAngle = 0x16c;
         inline constexpr uintptr_t TwistUpperAngle = 0x170;
         inline constexpr uintptr_t UpperAngle = 0x174;
    }

    namespace BaseCoreGuiConfiguration {
         inline constexpr uintptr_t Enabled = 0xa0;
    }

    namespace BasePart {
         inline constexpr uintptr_t AudioCanCollide = 0x124;
         inline constexpr uintptr_t CastShadow = 0x125;
         inline constexpr uintptr_t CollisionGroupReplicate = 0xc0;
         inline constexpr uintptr_t Color3 = 0x198;
         inline constexpr uintptr_t LocalTransparencyModifier = 0xf8;
         inline constexpr uintptr_t Locked = 0x126;
         inline constexpr uintptr_t Massless = 0x127;
         inline constexpr uintptr_t Primitive = 0x178;
         inline constexpr uintptr_t Reflectance = 0xfc;
         inline constexpr uintptr_t Shape = 0x1a8;
         inline constexpr uintptr_t TopParamA = 0x110;
         inline constexpr uintptr_t TopParamB = 0x114;
         inline constexpr uintptr_t Transparency = 0x120;
    }

    namespace BaseScript {
         inline constexpr uintptr_t LinkedSource = 0xf8;
    }

    namespace BaseWrap {
         inline constexpr uintptr_t CageMeshContent = 0xa8;
         inline constexpr uintptr_t CageOrigin = 0x150;
         inline constexpr uintptr_t HSRData = 0x140;
         inline constexpr uintptr_t ImportInProcess = 0x1b0;
         inline constexpr uintptr_t ImportOrigin = 0x180;
    }

    namespace Beam {
         inline constexpr uintptr_t Attachment0 = 0x150;
         inline constexpr uintptr_t Attachment1 = 0x160;
         inline constexpr uintptr_t Brightness = 0x170;
         inline constexpr uintptr_t Color = 0xe8;
         inline constexpr uintptr_t CurveSize0 = 0x174;
         inline constexpr uintptr_t CurveSize1 = 0x178;
         inline constexpr uintptr_t Enabled = 0x1a4;
         inline constexpr uintptr_t FaceCamera = 0x1a5;
         inline constexpr uintptr_t LightEmission = 0x17c;
         inline constexpr uintptr_t LightInfluence = 0x180;
         inline constexpr uintptr_t LocalTransparencyModifier = 0x184;
         inline constexpr uintptr_t Segments = 0x188;
         inline constexpr uintptr_t Texture = 0x130;
         inline constexpr uintptr_t TextureLength = 0x18c;
         inline constexpr uintptr_t TextureSpeed = 0x194;
         inline constexpr uintptr_t Transparency = 0xa8;
         inline constexpr uintptr_t Width0 = 0x198;
         inline constexpr uintptr_t Width1 = 0x19c;
         inline constexpr uintptr_t ZOffset = 0x1a0;
    }

    namespace BevelMesh {
         inline constexpr uintptr_t Bevel = 0xd0;
         inline constexpr uintptr_t Bulge = 0xd8;
         inline constexpr uintptr_t Data = 0xd4;
    }

    namespace BillboardGui {
         inline constexpr uintptr_t Active = 0x7bc;
         inline constexpr uintptr_t AlwaysOnTop = 0x7bd;
         inline constexpr uintptr_t Brightness = 0x7a0;
         inline constexpr uintptr_t ClipsDescendants = 0x7be;
         inline constexpr uintptr_t CurrentDistance = 0x7a4;
         inline constexpr uintptr_t DistanceLowerLimit = 0x7a8;
         inline constexpr uintptr_t DistanceStep = 0x7ac;
         inline constexpr uintptr_t DistanceUpperLimit = 0x7b0;
         inline constexpr uintptr_t ExtentsOffset = 0x768;
         inline constexpr uintptr_t ExtentsOffsetWorldSpace = 0x774;
         inline constexpr uintptr_t LightInfluence = 0x7b4;
         inline constexpr uintptr_t MaxDistance = 0x7b8;
         inline constexpr uintptr_t Size = 0x758;
         inline constexpr uintptr_t SizeOffset = 0x798;
         inline constexpr uintptr_t StudsOffset = 0x780;
         inline constexpr uintptr_t StudsOffsetWorldSpace = 0x78c;
    }

    namespace BloomEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t Intensity = 0xa8;
         inline constexpr uintptr_t Size = 0xac;
         inline constexpr uintptr_t Threshold = 0xb0;
    }

    namespace BlurEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t Size = 0xa8;
    }

    namespace BodyAngularVelocity {
         inline constexpr uintptr_t AngularVelocity = 0x278;
         inline constexpr uintptr_t MaxTorque = 0x284;
         inline constexpr uintptr_t P = 0x290;
    }

    namespace BodyColors {
         inline constexpr uintptr_t HeadColor = 0xb0;
    }

    namespace BodyForce {
         inline constexpr uintptr_t Force = 0x270;
    }

    namespace BodyGyro {
         inline constexpr uintptr_t D = 0x2b4;
         inline constexpr uintptr_t P = 0x2b8;
    }

    namespace BodyPartDescription {
         inline constexpr uintptr_t AssetId = 0xd0;
    }

    namespace BodyPosition {
         inline constexpr uintptr_t D = 0x290;
         inline constexpr uintptr_t MaxForce = 0x278;
         inline constexpr uintptr_t P = 0x294;
         inline constexpr uintptr_t Position = 0x284;
    }

    namespace BodyThrust {
         inline constexpr uintptr_t Force = 0x270;
    }

    namespace BodyVelocity {
         inline constexpr uintptr_t MaxForce = 0x278;
         inline constexpr uintptr_t P = 0x290;
         inline constexpr uintptr_t Velocity = 0x284;
    }

    namespace Bone {
         inline constexpr uintptr_t Transform = 0x170;
    }

    namespace BoolValue {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace BoxHandleAdornment {
         inline constexpr uintptr_t Size = 0x198;
    }

    namespace BrickColorValue {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace BubbleChatConfiguration {
         inline constexpr uintptr_t BubbleDuration = 0x104;
         inline constexpr uintptr_t BubblesSpacing = 0x108;
         inline constexpr uintptr_t MaxBubbles = 0x10c;
         inline constexpr uintptr_t MaxDistance = 0x110;
         inline constexpr uintptr_t MinimizeDistance = 0x114;
         inline constexpr uintptr_t TextColor3 = 0xf8;
         inline constexpr uintptr_t TextSize = 0xd8;
         inline constexpr uintptr_t VerticalStudsOffset = 0x118;
    }

    namespace BubbleChatMessageProperties {
         inline constexpr uintptr_t TailVisible = 0x130;
         inline constexpr uintptr_t TextSize = 0x110;
    }

    namespace ByteCode {
         inline constexpr uintptr_t Pointer = 0x10;
         inline constexpr uintptr_t Size = 0x28;
    }

    namespace CachedItem {
         inline constexpr uintptr_t FileMeshData = 0x40;
    }

    namespace Camera {
         inline constexpr uintptr_t CameraSubject = 0xb8;
         inline constexpr uintptr_t CameraType = 0x128;
         inline constexpr uintptr_t FieldOfView = 0x130;
         inline constexpr uintptr_t Focus = 0xf8;
         inline constexpr uintptr_t HeadScale = 0x138;
         inline constexpr uintptr_t ImagePlaneDepth = 0x2d4;
         inline constexpr uintptr_t NearPlaneZ = 0x140;
         inline constexpr uintptr_t OrthographicSize = 0x148;
         inline constexpr uintptr_t Position = 0xec;
         inline constexpr uintptr_t Rotation = 0xc8;
         inline constexpr uintptr_t ViewStretch = 0x150;
         inline constexpr uintptr_t Viewport = 0x28c;
         inline constexpr uintptr_t ViewportSize = 0x2cc;
    }

    namespace CanvasGroup {
         inline constexpr uintptr_t GroupTransparency = 0x9a4;
         inline constexpr uintptr_t ResolutionScale = 0x9a8;
    }

    namespace CapturesViewConfiguration {
         inline constexpr uintptr_t Open = 0xa8;
    }

    namespace ChannelSelectorSoundEffect {
         inline constexpr uintptr_t Channel = 0xf0;
    }

    namespace ChannelTabsConfiguration {
         inline constexpr uintptr_t BackgroundColor3 = 0xc8;
         inline constexpr uintptr_t BackgroundTransparency = 0xa8;
         inline constexpr uintptr_t Enabled = 0x114;
         inline constexpr uintptr_t TextSize = 0xb8;
         inline constexpr uintptr_t TextStrokeColor3 = 0xf8;
    }

    namespace CharacterMesh {
         inline constexpr uintptr_t BaseTextureId = 0xb8;
         inline constexpr uintptr_t BodyPart = 0x138;
         inline constexpr uintptr_t MeshId = 0xe8;
         inline constexpr uintptr_t OverlayTextureId = 0x118;
    }

    namespace ChatInputBarConfiguration {
         inline constexpr uintptr_t AutocompleteEnabled = 0x12c;
         inline constexpr uintptr_t Enabled = 0x12d;
         inline constexpr uintptr_t IsFocused = 0x12e;
         inline constexpr uintptr_t TextSize = 0xd8;
    }

    namespace ChatWindowConfiguration {
         inline constexpr uintptr_t BackgroundColor3 = 0xc8;
         inline constexpr uintptr_t BackgroundTransparency = 0xa8;
         inline constexpr uintptr_t Enabled = 0x110;
         inline constexpr uintptr_t HeightScale = 0xfc;
         inline constexpr uintptr_t TextSize = 0xb8;
         inline constexpr uintptr_t WidthScale = 0x10c;
    }

    namespace ChatWindowMessageProperties {
         inline constexpr uintptr_t TextColor3 = 0x120;
    }

    namespace ChorusSoundEffect {
         inline constexpr uintptr_t Depth = 0xe8;
         inline constexpr uintptr_t Rate = 0xf0;
    }

    namespace ClickDetector {
         inline constexpr uintptr_t MaxActivationDistance = 0xd8;
         inline constexpr uintptr_t MouseIcon = 0xb8;
    }

    namespace ClimbController {
         inline constexpr uintptr_t AccelerationTime = 0xd0;
         inline constexpr uintptr_t BalanceSpeed = 0xd8;
         inline constexpr uintptr_t MoveMaxForce = 0xdc;
    }

    namespace Clothing {
         inline constexpr uintptr_t Color3 = 0x110;
         inline constexpr uintptr_t Template = 0xf0;
    }

    namespace Clouds {
         inline constexpr uintptr_t Density = 0xb0;
         inline constexpr uintptr_t Enabled = 0xb4;
    }

    namespace Color3Value {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace ColorCorrectionEffect {
         inline constexpr uintptr_t Brightness = 0xb4;
         inline constexpr uintptr_t Contrast = 0xb8;
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t Saturation = 0xbc;
         inline constexpr uintptr_t TintColor = 0xa8;
    }

    namespace ColorGradingEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t TonemapperPreset = 0xa8;
    }

    namespace CompressorSoundEffect {
         inline constexpr uintptr_t Attack = 0xf8;
         inline constexpr uintptr_t GainMakeup = 0xfc;
         inline constexpr uintptr_t Ratio = 0x100;
         inline constexpr uintptr_t Release = 0x104;
         inline constexpr uintptr_t Threshold = 0x108;
    }

    namespace ConeHandleAdornment {
         inline constexpr uintptr_t Height = 0x198;
         inline constexpr uintptr_t Radius = 0x19c;
    }

    namespace Constraint {
         inline constexpr uintptr_t Enabled = 0xa9;
    }

    namespace ControllerBase {
         inline constexpr uintptr_t MoveSpeedFactor = 0xa8;
    }

    namespace ControllerManager {
         inline constexpr uintptr_t BaseMoveSpeed = 0x10c;
         inline constexpr uintptr_t BaseTurnSpeed = 0x110;
         inline constexpr uintptr_t FacingDirection = 0xe8;
         inline constexpr uintptr_t UpDirection = 0x100;
    }

    namespace ControllerPartSensor {
         inline constexpr uintptr_t LadderSearchHeight = 0x27c;
         inline constexpr uintptr_t LadderSearchOffset = 0x280;
         inline constexpr uintptr_t SearchDistance = 0x284;
    }

    namespace CustomEvent {
         inline constexpr uintptr_t PersistedCurrentValue = 0xa0;
    }

    namespace CylinderHandleAdornment {
         inline constexpr uintptr_t Angle = 0x198;
         inline constexpr uintptr_t Height = 0x19c;
         inline constexpr uintptr_t InnerRadius = 0x1a0;
    }

    namespace CylindricalConstraint {
         inline constexpr uintptr_t AngularRestitution = 0x1c8;
         inline constexpr uintptr_t AngularSpeed = 0x1cc;
         inline constexpr uintptr_t AngularVelocity = 0x1d0;
         inline constexpr uintptr_t InclinationAngle = 0x1d4;
         inline constexpr uintptr_t LowerAngle = 0x1d8;
         inline constexpr uintptr_t MotorMaxAngularAcceleration = 0x1dc;
         inline constexpr uintptr_t MotorMaxTorque = 0x1e0;
         inline constexpr uintptr_t ServoMaxTorque = 0x1e4;
         inline constexpr uintptr_t SoftlockAngularServoUponReachingTarget = 0x1f2;
         inline constexpr uintptr_t TargetAngle = 0x1e8;
         inline constexpr uintptr_t UpperAngle = 0x1ec;
    }

    namespace DataModel {
         inline constexpr uintptr_t CreatorId = 0x178;
         inline constexpr uintptr_t GameId = 0x180;
         inline constexpr uintptr_t GameLoaded = 0x5d0;
         inline constexpr uintptr_t JobId = 0x110;
         inline constexpr uintptr_t PlaceId = 0x188;
         inline constexpr uintptr_t PlaceVersion = 0x1a4;
         inline constexpr uintptr_t PrimitiveCount = 0x418;
         inline constexpr uintptr_t ScriptContext = 0x440;
         inline constexpr uintptr_t ServerIP = 0x5b8;
         inline constexpr uintptr_t ToRenderView1 = 0x1c0;
         inline constexpr uintptr_t ToRenderView2 = 0x8;
         inline constexpr uintptr_t ToRenderView3 = 0x28;
         inline constexpr uintptr_t Workspace = 0x150;
    }

    namespace DataModelMesh {
         inline constexpr uintptr_t Offset = 0xa8;
         inline constexpr uintptr_t Scale = 0xb4;
         inline constexpr uintptr_t VertexColor = 0xc0;
    }

    namespace DataStoreGetOptions {
         inline constexpr uintptr_t UseCache = 0xa0;
    }

    namespace DataStoreInfo {
         inline constexpr uintptr_t CreatedTime = 0xc0;
         inline constexpr uintptr_t UpdatedTime = 0xc8;
    }

    namespace DataStoreKeyInfo {
         inline constexpr uintptr_t CreatedTime = 0xc0;
         inline constexpr uintptr_t UpdatedTime = 0xc8;
    }

    namespace DataStoreObjectVersionInfo {
         inline constexpr uintptr_t CreatedTime = 0xc0;
         inline constexpr uintptr_t IsDeleted = 0xc8;
    }

    namespace DataStoreOptions {
         inline constexpr uintptr_t AllScopes = 0xa0;
    }

    namespace DataStoreService {
         inline constexpr uintptr_t AutomaticRetry = 0xb8;
         inline constexpr uintptr_t LegacyNamingScheme = 0xb9;
    }

    namespace Debris {
         inline constexpr uintptr_t MaxItems = 0xb8;
    }

    namespace DebuggerBreakpoint {
         inline constexpr uintptr_t Line = 0xa8;
    }

    namespace DebuggerManager {
         inline constexpr uintptr_t DebuggingEnabled = 0xb0;
    }

    namespace Decal {
         inline constexpr uintptr_t EmissiveMaskContent = 0xd0;
         inline constexpr uintptr_t LocalTransparencyModifier = 0x26c;
         inline constexpr uintptr_t MetalnessMapContent = 0x130;
         inline constexpr uintptr_t Rotation = 0x274;
         inline constexpr uintptr_t Shiny = 0x278;
         inline constexpr uintptr_t Specular = 0x27c;
         inline constexpr uintptr_t ZIndex = 0x284;
    }

    namespace DeferredAssetManagerService {
         inline constexpr uintptr_t JoiningPlaceId = 0xb8;
         inline constexpr uintptr_t JoiningUniverseId = 0xc0;
         inline constexpr uintptr_t PregameLoadingScreenOnly = 0xc8;
    }

    namespace DepthOfFieldEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t FarIntensity = 0xa8;
         inline constexpr uintptr_t FocusDistance = 0xac;
         inline constexpr uintptr_t InFocusRadius = 0xb0;
         inline constexpr uintptr_t NearIntensity = 0xb4;
    }

    namespace Dialog {
         inline constexpr uintptr_t ConversationDistance = 0xf0;
         inline constexpr uintptr_t GoodbyeChoiceActive = 0x100;
         inline constexpr uintptr_t InUse = 0x101;
         inline constexpr uintptr_t TriggerDistance = 0xfc;
    }

    namespace DistortionSoundEffect {
         inline constexpr uintptr_t Level = 0xe8;
    }

    namespace DockWidgetPluginGui {
         inline constexpr uintptr_t HostWidgetWasRestored = 0x8a8;
    }

    namespace DoubleConstrainedValue {
         inline constexpr uintptr_t MaxValue = 0xa8;
    }

    namespace DragDetector {
         inline constexpr uintptr_t ActivatedCursorIcon = 0x1b0;
         inline constexpr uintptr_t CursorIcon = 0xb8;
         inline constexpr uintptr_t MaxActivationDistance = 0xd8;
         inline constexpr uintptr_t MaxDragAngle = 0x298;
         inline constexpr uintptr_t MaxDragTranslation = 0x25c;
         inline constexpr uintptr_t MaxForce = 0x29c;
         inline constexpr uintptr_t MaxTorque = 0x2a0;
         inline constexpr uintptr_t MinDragAngle = 0x2a4;
         inline constexpr uintptr_t MinDragTranslation = 0x268;
         inline constexpr uintptr_t ReferenceInstance = 0x1e0;
         inline constexpr uintptr_t Responsiveness = 0x2b0;
    }

    namespace EchoSoundEffect {
         inline constexpr uintptr_t Delay = 0xe8;
         inline constexpr uintptr_t Feedback = 0xf0;
         inline constexpr uintptr_t WetLevel = 0xf4;
    }

    namespace EqualizerSoundEffect {
         inline constexpr uintptr_t HighGain = 0xe8;
         inline constexpr uintptr_t MidGain = 0xf0;
    }

    namespace ExperienceInviteOptions {
         inline constexpr uintptr_t InviteUser = 0x100;
    }

    namespace ExperienceStateCaptureService {
         inline constexpr uintptr_t HiddenSelectionEnabled = 0xb4;
         inline constexpr uintptr_t IsInBackground = 0xb5;
         inline constexpr uintptr_t IsInCaptureMode = 0xb6;
    }

    namespace ExperienceStateRecordingService {
         inline constexpr uintptr_t IsServerDataModelRecorderActive = 0xb8;
    }

    namespace Explosion {
         inline constexpr uintptr_t BlastRadius = 0xf0;
         inline constexpr uintptr_t DestroyJointRadiusPercent = 0xf4;
         inline constexpr uintptr_t LocalTransparencyModifier = 0xfc;
         inline constexpr uintptr_t TimeScale = 0x100;
         inline constexpr uintptr_t Visible = 0x104;
    }

    namespace FaceControls {
         inline constexpr uintptr_t ChinRaiser = 0xd0;
         inline constexpr uintptr_t ChinRaiserUpperLip = 0xd4;
         inline constexpr uintptr_t Corrugator = 0xd8;
         inline constexpr uintptr_t EyesLookDown = 0xdc;
         inline constexpr uintptr_t EyesLookLeft = 0xe0;
         inline constexpr uintptr_t EyesLookRight = 0xe4;
         inline constexpr uintptr_t EyesLookUp = 0xe8;
         inline constexpr uintptr_t FlatPucker = 0xec;
         inline constexpr uintptr_t Funneler = 0xf0;
         inline constexpr uintptr_t InternalOverrideFACSData = 0xa8;
         inline constexpr uintptr_t JawDrop = 0xf4;
         inline constexpr uintptr_t JawLeft = 0xf8;
         inline constexpr uintptr_t JawRight = 0xfc;
         inline constexpr uintptr_t LeftBrowLowerer = 0x100;
         inline constexpr uintptr_t LeftCheekPuff = 0x104;
         inline constexpr uintptr_t LeftCheekRaiser = 0x108;
         inline constexpr uintptr_t LeftDimpler = 0x10c;
         inline constexpr uintptr_t LeftEyeClosed = 0x110;
         inline constexpr uintptr_t LeftEyeUpperLidRaiser = 0x114;
         inline constexpr uintptr_t LeftInnerBrowRaiser = 0x118;
         inline constexpr uintptr_t LeftLipCornerDown = 0x11c;
         inline constexpr uintptr_t LeftLipCornerPuller = 0x120;
         inline constexpr uintptr_t LeftLipStretcher = 0x124;
         inline constexpr uintptr_t LeftLowerLipDepressor = 0x128;
         inline constexpr uintptr_t LeftNoseWrinkler = 0x12c;
         inline constexpr uintptr_t LeftOuterBrowRaiser = 0x130;
         inline constexpr uintptr_t LeftUpperLipRaiser = 0x134;
         inline constexpr uintptr_t LipPresser = 0x138;
         inline constexpr uintptr_t LipsTogether = 0x13c;
         inline constexpr uintptr_t LowerLipSuck = 0x140;
         inline constexpr uintptr_t MouthLeft = 0x144;
         inline constexpr uintptr_t MouthRight = 0x148;
         inline constexpr uintptr_t Pucker = 0x14c;
         inline constexpr uintptr_t RightBrowLowerer = 0x150;
         inline constexpr uintptr_t RightCheekPuff = 0x154;
         inline constexpr uintptr_t RightCheekRaiser = 0x158;
         inline constexpr uintptr_t RightDimpler = 0x15c;
         inline constexpr uintptr_t RightEyeClosed = 0x160;
         inline constexpr uintptr_t RightEyeUpperLidRaiser = 0x164;
         inline constexpr uintptr_t RightInnerBrowRaiser = 0x168;
         inline constexpr uintptr_t RightLipCornerDown = 0x16c;
         inline constexpr uintptr_t RightLipCornerPuller = 0x170;
         inline constexpr uintptr_t RightLipStretcher = 0x174;
         inline constexpr uintptr_t RightLowerLipDepressor = 0x178;
         inline constexpr uintptr_t RightNoseWrinkler = 0x17c;
         inline constexpr uintptr_t RightOuterBrowRaiser = 0x180;
         inline constexpr uintptr_t RightUpperLipRaiser = 0x184;
         inline constexpr uintptr_t TongueDown = 0x188;
         inline constexpr uintptr_t TongueOut = 0x18c;
         inline constexpr uintptr_t TongueUp = 0x190;
         inline constexpr uintptr_t UpperLipSuck = 0x194;
    }

    namespace FakeDataModel {
         inline constexpr uintptr_t Pointer = 0x8bcfd50;
         inline constexpr uintptr_t RealDataModel = 0x1f8;
    }

    namespace FileMeshData {
         inline constexpr uintptr_t AABBMax = 0x18c;
         inline constexpr uintptr_t AABBMin = 0x180;
         inline constexpr uintptr_t Faces = 0x30;
         inline constexpr uintptr_t FacesEnd = 0x38;
         inline constexpr uintptr_t Vertices = 0x0;
         inline constexpr uintptr_t VerticesEnd = 0x8;
    }

    namespace Fire {
         inline constexpr uintptr_t Color = 0xa8;
         inline constexpr uintptr_t Enabled = 0xd0;
         inline constexpr uintptr_t Heat = 0xc8;
         inline constexpr uintptr_t LocalTransparencyModifier = 0xc0;
         inline constexpr uintptr_t SecondaryColor = 0xb4;
         inline constexpr uintptr_t Size = 0xcc;
         inline constexpr uintptr_t TimeScale = 0xc4;
    }

    namespace FlangeSoundEffect {
         inline constexpr uintptr_t Depth = 0xe8;
         inline constexpr uintptr_t Rate = 0xf0;
    }

    namespace FloorWire {
         inline constexpr uintptr_t CycleOffset = 0x138;
         inline constexpr uintptr_t StudsBetweenTextures = 0x13c;
         inline constexpr uintptr_t TextureSize = 0x130;
         inline constexpr uintptr_t Velocity = 0x140;
         inline constexpr uintptr_t WireRadius = 0x144;
    }

    namespace ForceField {
         inline constexpr uintptr_t Visible = 0xa8;
    }

    namespace FriendsCallingInstance {
         inline constexpr uintptr_t ConversationId = 0xc0;
         inline constexpr uintptr_t InitiatorUserId = 0xc8;
         inline constexpr uintptr_t Volume = 0xd8;
    }

    namespace FriendsCallingParticipant {
         inline constexpr uintptr_t IsLocalMuted = 0xb8;
         inline constexpr uintptr_t IsSpeaking = 0xb9;
         inline constexpr uintptr_t UserId = 0xa0;
         inline constexpr uintptr_t Volume = 0xb4;
    }

    namespace FunctionalTest {
         inline constexpr uintptr_t AllowSleep = 0xc8;
    }

    namespace GamepadService {
         inline constexpr uintptr_t GamepadCursorEnabled = 0xb8;
    }

    namespace GetTextBoundsParams {
         inline constexpr uintptr_t Font = 0xc8;
         inline constexpr uintptr_t Text = 0xa8;
         inline constexpr uintptr_t Width = 0xd4;
    }

    namespace Glue {
         inline constexpr uintptr_t F0 = 0x178;
    }

    namespace GroundController {
         inline constexpr uintptr_t AccelerationLean = 0xd0;
         inline constexpr uintptr_t BalanceMaxTorque = 0xd8;
         inline constexpr uintptr_t BalanceSpeed = 0xdc;
         inline constexpr uintptr_t DecelerationTime = 0xe0;
         inline constexpr uintptr_t Friction = 0xe4;
         inline constexpr uintptr_t FrictionWeight = 0xe8;
         inline constexpr uintptr_t GroundOffset = 0xec;
         inline constexpr uintptr_t StandForce = 0xf0;
         inline constexpr uintptr_t StandSpeed = 0xf4;
         inline constexpr uintptr_t TurnSpeedFactor = 0xf8;
    }

    namespace GuiBase2D {
         inline constexpr uintptr_t AbsolutePosition = 0xfc;
         inline constexpr uintptr_t AbsoluteRotation = 0xd8;
         inline constexpr uintptr_t AbsoluteSize = 0x104;
         inline constexpr uintptr_t IsNotOccluded = 0x125;
         inline constexpr uintptr_t SelectionGroup = 0x126;
         inline constexpr uintptr_t TotalGroupScale = 0x120;
    }

    namespace GuiBase3d {
         inline constexpr uintptr_t Color3 = 0xc8;
         inline constexpr uintptr_t Transparency = 0xd4;
         inline constexpr uintptr_t Visible = 0xd8;
    }

    namespace GuiButton {
         inline constexpr uintptr_t AutoButtonColor = 0x9e4;
         inline constexpr uintptr_t Modal = 0x9e5;
         inline constexpr uintptr_t MouseButton1ClickConnectionCount = 0x9c8;
         inline constexpr uintptr_t MouseButton1DownConnectionCount = 0x9cc;
         inline constexpr uintptr_t MouseButton2ClickConnectionCount = 0x9d4;
         inline constexpr uintptr_t MouseButton2DownConnectionCount = 0x9d8;
         inline constexpr uintptr_t MouseButton2UpConnectionCount = 0x9dc;
         inline constexpr uintptr_t Selected = 0x9e6;
    }

    namespace GuiObject {
         inline constexpr uintptr_t Active = 0x598;
         inline constexpr uintptr_t AnchorPoint = 0x548;
         inline constexpr uintptr_t BackgroundColor3 = 0x530;
         inline constexpr uintptr_t BackgroundTransparency = 0x53c;
         inline constexpr uintptr_t BorderColor3 = 0x53c;
         inline constexpr uintptr_t BorderSizePixel = 0x55c;
         inline constexpr uintptr_t ClipsDescendants = 0x599;
         inline constexpr uintptr_t DragBeginConnectionCount = 0x560;
         inline constexpr uintptr_t DragStoppedConnectionCount = 0x564;
         inline constexpr uintptr_t Draggable = 0x59a;
         inline constexpr uintptr_t Image = 0x9a8;
         inline constexpr uintptr_t Interactable = 0x59b;
         inline constexpr uintptr_t LayoutOrder = 0x56c;
         inline constexpr uintptr_t MouseEnterConnectionCount = 0x570;
         inline constexpr uintptr_t MouseLeaveConnectionCount = 0x574;
         inline constexpr uintptr_t MouseMovedConnectionCount = 0x578;
         inline constexpr uintptr_t MouseWheelBackwardConnectionCount = 0x57c;
         inline constexpr uintptr_t MouseWheelForwardConnectionCount = 0x580;
         inline constexpr uintptr_t Position = 0x500;
         inline constexpr uintptr_t RichText = 0xba0;
         inline constexpr uintptr_t Rotation = 0xd8;
         inline constexpr uintptr_t ScreenGui_Enabled = 0x4b4;
         inline constexpr uintptr_t Selectable = 0x59c;
         inline constexpr uintptr_t SelectionOrder = 0x588;
         inline constexpr uintptr_t Size = 0x520;
         inline constexpr uintptr_t Text = 0xe08;
         inline constexpr uintptr_t TextColor3 = 0xeb8;
         inline constexpr uintptr_t Visible = 0x59d;
         inline constexpr uintptr_t ZIndex = 0x594;
    }

    namespace GuiService {
         inline constexpr uintptr_t GuiNavigationEnabled = 0xf8;
         inline constexpr uintptr_t MenuIsOpen = 0xf9;
         inline constexpr uintptr_t TouchControlsEnabled = 0xfa;
         inline constexpr uintptr_t ViewportSizeInMM = 0xe8;
    }

    namespace HandleAdornment {
         inline constexpr uintptr_t AlwaysOnTop = 0x14c;
    }

    namespace Handles {
         inline constexpr uintptr_t MouseButton1UpConnectionCount = 0x118;
         inline constexpr uintptr_t MouseDragConnectionCount = 0x11c;
         inline constexpr uintptr_t MouseEnterConnectionCount = 0x120;
         inline constexpr uintptr_t MouseLeaveConnectionCount = 0x124;
    }

    namespace HapticEffect {
         inline constexpr uintptr_t Position = 0xc8;
         inline constexpr uintptr_t Radius = 0xd4;
    }

    namespace HiddenSurfaceRemovalAsset {
         inline constexpr uintptr_t HSRMeshIdData = 0xc0;
    }

    namespace Highlight {
         inline constexpr uintptr_t FillTransparency = 0xd4;
         inline constexpr uintptr_t OutlineTransparency = 0xdc;
    }

    namespace HingeConstraint {
         inline constexpr uintptr_t AngularSpeed = 0x168;
         inline constexpr uintptr_t AngularVelocity = 0x16c;
         inline constexpr uintptr_t LowerAngle = 0x170;
         inline constexpr uintptr_t MotorMaxAcceleration = 0x174;
         inline constexpr uintptr_t MotorMaxTorque = 0x178;
         inline constexpr uintptr_t Radius = 0x17c;
         inline constexpr uintptr_t Restitution = 0x180;
         inline constexpr uintptr_t ServoMaxTorque = 0x184;
         inline constexpr uintptr_t TargetAngle = 0x188;
         inline constexpr uintptr_t UpperAngle = 0x18c;
    }

    namespace HttpService {
         inline constexpr uintptr_t HttpEnabled = 0xb0;
    }

    namespace Humanoid {
         inline constexpr uintptr_t AutoJumpEnabled = 0x1c4;
         inline constexpr uintptr_t AutoRotate = 0x1c5;
         inline constexpr uintptr_t AutomaticScalingEnabled = 0x1c6;
         inline constexpr uintptr_t BreakJointsOnDeath = 0x1c7;
         inline constexpr uintptr_t CameraMinDistance = 0x164;
         inline constexpr uintptr_t CameraOffset = 0x118;
         inline constexpr uintptr_t DisplayDistanceType = 0x170;
         inline constexpr uintptr_t DisplayName = 0xa8;
         inline constexpr uintptr_t EvaluateStateMachine = 0x1c8;
         inline constexpr uintptr_t FloorMaterial = 0x174;
         inline constexpr uintptr_t Health = 0x180;
         inline constexpr uintptr_t HealthDisplayDistance = 0x178;
         inline constexpr uintptr_t HealthDisplayType = 0x17c;
         inline constexpr uintptr_t Health_XML = 0x180;
         inline constexpr uintptr_t HipHeight = 0x184;
         inline constexpr uintptr_t HumanoidRootPart = 0x460;
         inline constexpr uintptr_t HumanoidState = 0x8a8;
         inline constexpr uintptr_t HumanoidStateID = 0x20;
         inline constexpr uintptr_t InternalBodyScale = 0x124;
         inline constexpr uintptr_t InternalHeadScale = 0x188;
         inline constexpr uintptr_t InternalOriginalHipHeight = 0x18c;
         inline constexpr uintptr_t IsWalking = 0xa27;
         inline constexpr uintptr_t Jump = 0x1ca;
         inline constexpr uintptr_t JumpHeight = 0x190;
         inline constexpr uintptr_t JumpPower = 0x194;
         inline constexpr uintptr_t MaxHealth = 0x198;
         inline constexpr uintptr_t MaxSlopeAngle = 0x19c;
         inline constexpr uintptr_t MoveDirection = 0x130;
         inline constexpr uintptr_t MoveToPart = 0x108;
         inline constexpr uintptr_t MoveToPoint = 0x154;
         inline constexpr uintptr_t NameDisplayDistance = 0x1a0;
         inline constexpr uintptr_t NameOcclusion = 0x1a4;
         inline constexpr uintptr_t NoFloorTimerState = 0x1ac;
         inline constexpr uintptr_t PlatformStand = 0x1cc;
         inline constexpr uintptr_t PlatformStatePointer = 0x0;
         inline constexpr uintptr_t RequiresNeck = 0x1cd;
         inline constexpr uintptr_t RigType = 0x1b0;
         inline constexpr uintptr_t SeatPart = 0xf8;
         inline constexpr uintptr_t Sit = 0x1cd;
         inline constexpr uintptr_t Strafe = 0x1cf;
         inline constexpr uintptr_t TargetPoint = 0x13c;
         inline constexpr uintptr_t UseJumpPower = 0x1d0;
         inline constexpr uintptr_t WalkDirection = 0x148;
         inline constexpr uintptr_t WalkTimer = 0x0;
         inline constexpr uintptr_t WalkToPoint = 0x154;
         inline constexpr uintptr_t Walkspeed = 0x1c0;
         inline constexpr uintptr_t WalkspeedCheck = 0x39c;
    }

    namespace HumanoidDescription {
         inline constexpr uintptr_t BodyTypeScale = 0x128;
         inline constexpr uintptr_t ClimbAnimation = 0xc8;
         inline constexpr uintptr_t DepthScale = 0x12c;
         inline constexpr uintptr_t Face = 0xd0;
         inline constexpr uintptr_t FallAnimation = 0xd8;
         inline constexpr uintptr_t GraphicTShirt = 0xe0;
         inline constexpr uintptr_t HeadScale = 0x130;
         inline constexpr uintptr_t HeightScale = 0x134;
         inline constexpr uintptr_t IdleAnimation = 0xe8;
         inline constexpr uintptr_t JumpAnimation = 0xf0;
         inline constexpr uintptr_t MoodAnimation = 0xf8;
         inline constexpr uintptr_t NumberEmotesLoaded = 0x138;
         inline constexpr uintptr_t Pants = 0x100;
         inline constexpr uintptr_t ProportionScale = 0x13c;
         inline constexpr uintptr_t RunAnimation = 0x108;
         inline constexpr uintptr_t Shirt = 0x110;
         inline constexpr uintptr_t SwimAnimation = 0x118;
         inline constexpr uintptr_t WalkAnimation = 0x120;
         inline constexpr uintptr_t WidthScale = 0x140;
    }

    namespace HumanoidRigDescription {
         inline constexpr uintptr_t ChestRangeMax = 0x670;
         inline constexpr uintptr_t ChestRangeMin = 0x67c;
         inline constexpr uintptr_t ChestSize = 0x880;
         inline constexpr uintptr_t ChestTposeAdjustment = 0x220;
         inline constexpr uintptr_t HeadBaseRangeMax = 0x688;
         inline constexpr uintptr_t HeadBaseRangeMin = 0x694;
         inline constexpr uintptr_t HeadBaseSize = 0x884;
         inline constexpr uintptr_t HeadBaseTposeAdjustment = 0x250;
         inline constexpr uintptr_t LeftAnkleRangeMax = 0x6a0;
         inline constexpr uintptr_t LeftAnkleRangeMin = 0x6ac;
         inline constexpr uintptr_t LeftAnkleSize = 0x888;
         inline constexpr uintptr_t LeftAnkleTposeAdjustment = 0x280;
         inline constexpr uintptr_t LeftClavicleRangeMax = 0x6b8;
         inline constexpr uintptr_t LeftClavicleRangeMin = 0x6c4;
         inline constexpr uintptr_t LeftClavicleSize = 0x88c;
         inline constexpr uintptr_t LeftClavicleTposeAdjustment = 0x2b0;
         inline constexpr uintptr_t LeftElbowRangeMax = 0x6d0;
         inline constexpr uintptr_t LeftElbowRangeMin = 0x6dc;
         inline constexpr uintptr_t LeftElbowSize = 0x890;
         inline constexpr uintptr_t LeftElbowTposeAdjustment = 0x2e0;
         inline constexpr uintptr_t LeftHipRangeMax = 0x6e8;
         inline constexpr uintptr_t LeftHipRangeMin = 0x6f4;
         inline constexpr uintptr_t LeftHipSize = 0x894;
         inline constexpr uintptr_t LeftHipTposeAdjustment = 0x310;
         inline constexpr uintptr_t LeftKneeRangeMax = 0x700;
         inline constexpr uintptr_t LeftKneeRangeMin = 0x70c;
         inline constexpr uintptr_t LeftKneeSize = 0x898;
         inline constexpr uintptr_t LeftKneeTposeAdjustment = 0x340;
         inline constexpr uintptr_t LeftShoulderRangeMax = 0x718;
         inline constexpr uintptr_t LeftShoulderRangeMin = 0x724;
         inline constexpr uintptr_t LeftShoulderSize = 0x89c;
         inline constexpr uintptr_t LeftShoulderTposeAdjustment = 0x370;
         inline constexpr uintptr_t LeftToeBaseRangeMax = 0x730;
         inline constexpr uintptr_t LeftToeBaseRangeMin = 0x73c;
         inline constexpr uintptr_t LeftToeBaseSize = 0x8a0;
         inline constexpr uintptr_t LeftToeBaseTposeAdjustment = 0x3a0;
         inline constexpr uintptr_t LeftWristRangeMax = 0x748;
         inline constexpr uintptr_t LeftWristRangeMin = 0x754;
         inline constexpr uintptr_t LeftWristSize = 0x8a4;
         inline constexpr uintptr_t LeftWristTposeAdjustment = 0x3d0;
         inline constexpr uintptr_t NeckRangeMax = 0x760;
         inline constexpr uintptr_t NeckRangeMin = 0x76c;
         inline constexpr uintptr_t NeckSize = 0x8a8;
         inline constexpr uintptr_t NeckTposeAdjustment = 0x400;
         inline constexpr uintptr_t OriginOffset = 0x430;
         inline constexpr uintptr_t RightAnkleRangeMax = 0x778;
         inline constexpr uintptr_t RightAnkleRangeMin = 0x784;
         inline constexpr uintptr_t RightAnkleSize = 0x8ac;
         inline constexpr uintptr_t RightAnkleTposeAdjustment = 0x460;
         inline constexpr uintptr_t RightClavicleRangeMax = 0x790;
         inline constexpr uintptr_t RightClavicleRangeMin = 0x79c;
         inline constexpr uintptr_t RightClavicleSize = 0x8b0;
         inline constexpr uintptr_t RightClavicleTposeAdjustment = 0x490;
         inline constexpr uintptr_t RightElbowRangeMax = 0x7a8;
         inline constexpr uintptr_t RightElbowRangeMin = 0x7b4;
         inline constexpr uintptr_t RightElbowSize = 0x8b4;
         inline constexpr uintptr_t RightElbowTposeAdjustment = 0x4c0;
         inline constexpr uintptr_t RightHipRangeMax = 0x7c0;
         inline constexpr uintptr_t RightHipRangeMin = 0x7cc;
         inline constexpr uintptr_t RightHipSize = 0x8b8;
         inline constexpr uintptr_t RightHipTposeAdjustment = 0x4f0;
         inline constexpr uintptr_t RightKneeRangeMax = 0x7d8;
         inline constexpr uintptr_t RightKneeRangeMin = 0x7e4;
         inline constexpr uintptr_t RightKneeSize = 0x8bc;
         inline constexpr uintptr_t RightKneeTposeAdjustment = 0x520;
         inline constexpr uintptr_t RightShoulderRangeMax = 0x7f0;
         inline constexpr uintptr_t RightShoulderRangeMin = 0x7fc;
         inline constexpr uintptr_t RightShoulderSize = 0x8c0;
         inline constexpr uintptr_t RightShoulderTposeAdjustment = 0x550;
         inline constexpr uintptr_t RightToeBaseRangeMax = 0x808;
         inline constexpr uintptr_t RightToeBaseRangeMin = 0x814;
         inline constexpr uintptr_t RightToeBaseSize = 0x8c4;
         inline constexpr uintptr_t RightToeBaseTposeAdjustment = 0x580;
         inline constexpr uintptr_t RightWristRangeMax = 0x820;
         inline constexpr uintptr_t RightWristRangeMin = 0x82c;
         inline constexpr uintptr_t RightWristSize = 0x8c8;
         inline constexpr uintptr_t RightWristTposeAdjustment = 0x5b0;
         inline constexpr uintptr_t RootRangeMax = 0x838;
         inline constexpr uintptr_t RootRangeMin = 0x844;
         inline constexpr uintptr_t RootSize = 0x8cc;
         inline constexpr uintptr_t RootTposeAdjustment = 0x5e0;
         inline constexpr uintptr_t SpineRangeMax = 0x850;
         inline constexpr uintptr_t SpineRangeMin = 0x85c;
         inline constexpr uintptr_t SpineSize = 0x8d0;
         inline constexpr uintptr_t SpineTposeAdjustment = 0x610;
         inline constexpr uintptr_t WaistRangeMax = 0x868;
         inline constexpr uintptr_t WaistRangeMin = 0x874;
         inline constexpr uintptr_t WaistSize = 0x8d4;
         inline constexpr uintptr_t WaistTposeAdjustment = 0x640;
    }

    namespace IKControl {
         inline constexpr uintptr_t Enabled = 0x158;
         inline constexpr uintptr_t EndEffectorOffset = 0xe8;
         inline constexpr uintptr_t Offset = 0x118;
         inline constexpr uintptr_t Priority = 0x148;
         inline constexpr uintptr_t SmoothTime = 0x14c;
         inline constexpr uintptr_t Weight = 0x154;
    }

    namespace ImageButton {
         inline constexpr uintptr_t ContentImageSize = 0xd8c;
         inline constexpr uintptr_t ImageRectOffset = 0xd94;
    }

    namespace ImageLabel {
         inline constexpr uintptr_t ContentImageSize = 0xaac;
         inline constexpr uintptr_t ImageRectOffset = 0xab4;
         inline constexpr uintptr_t ImageRectSize = 0xabc;
         inline constexpr uintptr_t SliceCenter = 0xa80;
         inline constexpr uintptr_t SliceScale = 0xad0;
         inline constexpr uintptr_t TileSize = 0xa90;
    }

    namespace IncrementalPatchBuilder {
         inline constexpr uintptr_t AddPathsToBundle = 0xb8;
         inline constexpr uintptr_t HighCompression = 0xb9;
    }

    namespace InputAction {
         inline constexpr uintptr_t Enabled = 0xfc;
    }

    namespace InputBinding {
         inline constexpr uintptr_t ClampMagnitudeToOne = 0x168;
         inline constexpr uintptr_t PointerIndex = 0x140;
         inline constexpr uintptr_t PressedThreshold = 0x144;
         inline constexpr uintptr_t ResponseCurve = 0x150;
         inline constexpr uintptr_t Scale = 0x158;
         inline constexpr uintptr_t Vector2Scale = 0x124;
         inline constexpr uintptr_t Vector3Scale = 0x118;
    }

    namespace InputContext {
         inline constexpr uintptr_t Priority = 0xa8;
    }

    namespace InputObject {
         inline constexpr uintptr_t Delta = 0xa8;
    }

    namespace InsertService {
         inline constexpr uintptr_t AllowInsertFreeModels = 0xb0;
    }

    namespace Instance {
         inline constexpr uintptr_t ChildrenEnd = 0x8;
         inline constexpr uintptr_t ChildrenLayout = 0x1;
         inline constexpr uintptr_t ChildrenStart = 0x78;
         inline constexpr uintptr_t ClassBase = 0x1b0;
         inline constexpr uintptr_t ClassDescriptor = 0x18;
         inline constexpr uintptr_t ClassName = 0x8;
         inline constexpr uintptr_t Name = 0x8;
         inline constexpr uintptr_t NameContainer = 0x70;
         inline constexpr uintptr_t Parent = 0x68;
         inline constexpr uintptr_t This = 0x8;
    }

    namespace IntConstrainedValue {
         inline constexpr uintptr_t MaxValue = 0xa8;
         inline constexpr uintptr_t MinValue = 0xb0;
    }

    namespace InternalSyncItem {
         inline constexpr uintptr_t AutoSync = 0xd0;
         inline constexpr uintptr_t Enabled = 0xd1;
    }

    namespace IntValue {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace JointInstance {
         inline constexpr uintptr_t Enabled = 0xa8;
    }

    namespace Keyframe {
         inline constexpr uintptr_t Time = 0xa8;
    }

    namespace KeyframeSequence {
         inline constexpr uintptr_t AuthoredHipHeight = 0xd0;
    }

    namespace Light {
         inline constexpr uintptr_t Brightness = 0xbc;
         inline constexpr uintptr_t Color = 0xb0;
         inline constexpr uintptr_t Enabled = 0xc0;
         inline constexpr uintptr_t Shadows = 0xc1;
    }

    namespace Lighting {
         inline constexpr uintptr_t Ambient = 0xc0;
         inline constexpr uintptr_t Brightness = 0x108;
         inline constexpr uintptr_t ClockTime = 0xb8;
         inline constexpr uintptr_t ColorShift_Bottom = 0xd8;
         inline constexpr uintptr_t ColorShift_Top = 0xcc;
         inline constexpr uintptr_t EnvironmentDiffuseScale = 0x10c;
         inline constexpr uintptr_t EnvironmentSpecularScale = 0x110;
         inline constexpr uintptr_t ExposureCompensation = 0x114;
         inline constexpr uintptr_t FogColor = 0xe4;
         inline constexpr uintptr_t FogEnd = 0x11c;
         inline constexpr uintptr_t FogStart = 0x120;
         inline constexpr uintptr_t GeographicLatitude = 0x124;
         inline constexpr uintptr_t GlobalShadows = 0x134;
         inline constexpr uintptr_t GradientBottom = 0x180;
         inline constexpr uintptr_t GradientTop = 0x140;
         inline constexpr uintptr_t LightColor = 0x14c;
         inline constexpr uintptr_t LightDirection = 0x158;
         inline constexpr uintptr_t MoonPosition = 0x174;
         inline constexpr uintptr_t OutdoorAmbient = 0xf0;
         inline constexpr uintptr_t ShadowSoftness = 0x12c;
         inline constexpr uintptr_t Sky = 0x1b8;
         inline constexpr uintptr_t Source = 0x164;
         inline constexpr uintptr_t SunPosition = 0x168;
    }

    namespace LineForce {
         inline constexpr uintptr_t ApplyAtCenterOfMass = 0x168;
         inline constexpr uintptr_t Magnitude = 0x160;
    }

    namespace LineHandleAdornment {
         inline constexpr uintptr_t Length = 0x198;
         inline constexpr uintptr_t Thickness = 0x19c;
    }

    namespace LocalizationService {
         inline constexpr uintptr_t IsImageCaptureEnabled = 0x128;
         inline constexpr uintptr_t ShouldUseCloudTable = 0x129;
    }

    namespace LocalizationTable {
         inline constexpr uintptr_t SourceLocaleId = 0xa8;
    }

    namespace LocalScript {
         inline constexpr uintptr_t ByteCode = 0x0;
         inline constexpr uintptr_t GUID = 0xc0;
         inline constexpr uintptr_t Hash = 0x190;
    }

    namespace LodDataEntity {
         inline constexpr uintptr_t SlimReplicationTimestampSec = 0xf0;
    }

    namespace LRUHolder {
         inline constexpr uintptr_t MemEnforcedLRUCache = 0x20;
    }

    namespace LRUNode {
         inline constexpr uintptr_t AssetID = 0x10;
         inline constexpr uintptr_t CachedItem = 0x40;
         inline constexpr uintptr_t Next = 0x0;
    }

    namespace LuaSourceContainer {
         inline constexpr uintptr_t CachedRemoteSource = 0xa8;
         inline constexpr uintptr_t CachedRemoteSourceLoadState = 0xe0;
         inline constexpr uintptr_t ScriptGuid = 0xc0;
    }

    namespace MakeupDescription {
         inline constexpr uintptr_t AssetId = 0xb0;
         inline constexpr uintptr_t Order = 0xbc;
    }

    namespace MaterialColors {
         inline constexpr uintptr_t Asphalt = 0x30;
         inline constexpr uintptr_t Basalt = 0x27;
         inline constexpr uintptr_t Brick = 0xf;
         inline constexpr uintptr_t Cobblestone = 0x33;
         inline constexpr uintptr_t Concrete = 0xc;
         inline constexpr uintptr_t CrackedLava = 0x2d;
         inline constexpr uintptr_t Glacier = 0x1b;
         inline constexpr uintptr_t Grass = 0x6;
         inline constexpr uintptr_t Ground = 0x2a;
         inline constexpr uintptr_t Ice = 0x36;
         inline constexpr uintptr_t LeafyGrass = 0x39;
         inline constexpr uintptr_t Limestone = 0x3f;
         inline constexpr uintptr_t Mud = 0x24;
         inline constexpr uintptr_t Pavement = 0x42;
         inline constexpr uintptr_t Rock = 0x18;
         inline constexpr uintptr_t Salt = 0x3c;
         inline constexpr uintptr_t Sand = 0x12;
         inline constexpr uintptr_t Sandstone = 0x21;
         inline constexpr uintptr_t Slate = 0x9;
         inline constexpr uintptr_t Snow = 0x1e;
         inline constexpr uintptr_t WoodPlanks = 0x15;
    }

    namespace MaterialVariant {
         inline constexpr uintptr_t ColorMapContent = 0xa8;
         inline constexpr uintptr_t EmissiveMaskContent = 0xd8;
         inline constexpr uintptr_t MetalnessMapContent = 0x108;
    }

    namespace MemEnforcedLRUCache {
         inline constexpr uintptr_t Head = 0x8;
    }

    namespace MeshContentProvider {
         inline constexpr uintptr_t LRUHolder = 0xc8;
    }

    namespace MeshPart {
         inline constexpr uintptr_t HasSkinnedMesh = 0x36e;
         inline constexpr uintptr_t JointOffset = 0x358;
         inline constexpr uintptr_t MeshContent = 0x2f0;
         inline constexpr uintptr_t MeshId = 0x300;
         inline constexpr uintptr_t Texture = 0x330;
         inline constexpr uintptr_t TextureContent = 0x320;
         inline constexpr uintptr_t VertexCount = 0x368;
    }

    namespace Message {
         inline constexpr uintptr_t Text = 0xa8;
    }

    namespace Misc {
         inline constexpr uintptr_t Adornee = 0xe0;
         inline constexpr uintptr_t AnimationId = 0xb0;
         inline constexpr uintptr_t StringLength = 0x10;
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace Model {
         inline constexpr uintptr_t ModelMeshCFrame = 0xf0;
         inline constexpr uintptr_t ModelMeshData = 0xd8;
         inline constexpr uintptr_t PrimaryPart = 0x248;
         inline constexpr uintptr_t Scale = 0x134;
         inline constexpr uintptr_t WorldPivotData = 0xe8;
    }

    namespace ModuleScript {
         inline constexpr uintptr_t ByteCode = 0x0;
         inline constexpr uintptr_t GUID = 0xc0;
         inline constexpr uintptr_t Hash = 0x350;
         inline constexpr uintptr_t IsCoreScript = 0x0;
         inline constexpr uintptr_t LinkedSource = 0xf8;
    }

    namespace Motor6D {
         inline constexpr uintptr_t EnableSkinning = 0x1a0;
    }

    namespace MouseService {
         inline constexpr uintptr_t InputObject = 0xe0;
         inline constexpr uintptr_t InputObject2 = 0xf0;
         inline constexpr uintptr_t MousePosition = 0xc4;
         inline constexpr uintptr_t SensitivityPointer = 0x0;
    }

    namespace NoCollisionConstraint {
         inline constexpr uintptr_t Enabled = 0xc8;
    }

    namespace NotificationService {
         inline constexpr uintptr_t IsConnected = 0xd0;
         inline constexpr uintptr_t IsLuaChatEnabled = 0xd1;
         inline constexpr uintptr_t IsLuaGameDetailsEnabled = 0xd2;
    }

    namespace NumberPose {
         inline constexpr uintptr_t Value = 0xc0;
    }

    namespace NumberValue {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace PackageLink {
         inline constexpr uintptr_t AutoUpdate = 0x12c;
         inline constexpr uintptr_t CanAutoUpdate = 0x12d;
         inline constexpr uintptr_t HasNewVersion = 0x12e;
         inline constexpr uintptr_t ModifiedState = 0x128;
         inline constexpr uintptr_t PackageContentSerialize = 0xa8;
         inline constexpr uintptr_t PackageGuid = 0x118;
    }

    namespace Packages {
         inline constexpr uintptr_t IsDehydrated = 0xb8;
         inline constexpr uintptr_t ShellPackagesCount = 0xb0;
    }

    namespace Pages {
         inline constexpr uintptr_t IsFinished = 0xa0;
    }

    namespace ParabolaAdornment {
         inline constexpr uintptr_t A = 0xf0;
         inline constexpr uintptr_t B = 0xf4;
         inline constexpr uintptr_t C = 0xf8;
         inline constexpr uintptr_t Thickness = 0x100;
    }

    namespace ParticleEmitter {
         inline constexpr uintptr_t Acceleration = 0x1d0;
         inline constexpr uintptr_t Brightness = 0x20c;
         inline constexpr uintptr_t Drag = 0x210;
         inline constexpr uintptr_t FlipbookBlendFrames = 0x259;
         inline constexpr uintptr_t FlipbookFramerate = 0x1dc;
         inline constexpr uintptr_t FlipbookSizeX = 0x220;
         inline constexpr uintptr_t FlipbookSizeY = 0x224;
         inline constexpr uintptr_t FlipbookStartRandom = 0x25a;
         inline constexpr uintptr_t Lifetime = 0x1e4;
         inline constexpr uintptr_t LightEmission = 0x228;
         inline constexpr uintptr_t LightInfluence = 0x22c;
         inline constexpr uintptr_t LocalTransparencyModifier = 0x230;
         inline constexpr uintptr_t LockedToPart = 0x25b;
         inline constexpr uintptr_t Rate = 0x238;
         inline constexpr uintptr_t RotSpeed = 0x1ec;
         inline constexpr uintptr_t Rotation = 0x1f4;
         inline constexpr uintptr_t ShapePartial = 0x244;
         inline constexpr uintptr_t Size = 0xa8;
         inline constexpr uintptr_t Speed = 0x1fc;
         inline constexpr uintptr_t SpreadAngle = 0x204;
         inline constexpr uintptr_t Squash = 0xe8;
         inline constexpr uintptr_t Texture = 0x1b0;
         inline constexpr uintptr_t TimeScale = 0x24c;
         inline constexpr uintptr_t VelocityInheritance = 0x250;
         inline constexpr uintptr_t WindAffectsDrag = 0x25c;
         inline constexpr uintptr_t ZOffset = 0x254;
    }

    namespace PartOperation {
         inline constexpr uintptr_t ChildData = 0x320;
         inline constexpr uintptr_t ChildData2 = 0x380;
         inline constexpr uintptr_t ComponentIndex = 0x398;
         inline constexpr uintptr_t MeshData = 0x358;
         inline constexpr uintptr_t MeshData2 = 0x390;
         inline constexpr uintptr_t OffCentered = 0x3ac;
         inline constexpr uintptr_t SmoothingAngle = 0x3a4;
         inline constexpr uintptr_t UsePartColor = 0x3ad;
    }

    namespace PartOperationAsset {
         inline constexpr uintptr_t MeshData = 0xc0;
    }

    namespace Path2D {
         inline constexpr uintptr_t SelectedControlPoint = 0xdc;
         inline constexpr uintptr_t Thickness = 0xe0;
         inline constexpr uintptr_t Transparency = 0xe4;
         inline constexpr uintptr_t ZIndex = 0xe8;
    }

    namespace PathfindingLink {
         inline constexpr uintptr_t IsBidirectional = 0xe8;
         inline constexpr uintptr_t Label = 0xa8;
    }

    namespace PathfindingModifier {
         inline constexpr uintptr_t Label = 0xa8;
         inline constexpr uintptr_t PassThrough = 0xc8;
    }

    namespace PitchShiftSoundEffect {
         inline constexpr uintptr_t Octave = 0xe8;
    }

    namespace Player {
         inline constexpr uintptr_t AccountAge = 0x34c;
         inline constexpr uintptr_t AppearanceDidLoad = 0x3b0;
         inline constexpr uintptr_t AutoJumpEnabled = 0x3b1;
         inline constexpr uintptr_t BanningEnabled = 0x13c;
         inline constexpr uintptr_t CameraFieldOfView = 0x354;
         inline constexpr uintptr_t CameraFrustumRequested = 0x3b2;
         inline constexpr uintptr_t CameraMaxZoomDistance = 0x358;
         inline constexpr uintptr_t CameraMinZoomDistance = 0x35c;
         inline constexpr uintptr_t CameraMode = 0x360;
         inline constexpr uintptr_t CameraViewportSize = 0x344;
         inline constexpr uintptr_t CanLoadCharacterAppearance = 0x3b3;
         inline constexpr uintptr_t CharacterAppearanceId = 0x2f0;
         inline constexpr uintptr_t CharacterAutoLoads = 0x13d;
         inline constexpr uintptr_t ChararacterRegionId = 0x338;
         inline constexpr uintptr_t CloudEditCameraCoordinateFrame = 0x308;
         inline constexpr uintptr_t CloudEditPlayerActive = 0x3b4;
         inline constexpr uintptr_t DataComplexityLimit = 0x368;
         inline constexpr uintptr_t DataReady = 0x3b5;
         inline constexpr uintptr_t DevEnableMouseLock = 0x3b6;
         inline constexpr uintptr_t DisplayName = 0x128;
         inline constexpr uintptr_t FollowUserId = 0x2f8;
         inline constexpr uintptr_t GameplayPaused = 0x3b7;
         inline constexpr uintptr_t HasRobloxSubscription = 0x3b8;
         inline constexpr uintptr_t HasVerifiedBadge = 0x3b9;
         inline constexpr uintptr_t HealthDisplayDistance = 0x384;
         inline constexpr uintptr_t InputLatency = 0x388;
         inline constexpr uintptr_t InternalCharacterAppearanceLoaded = 0x3ba;
         inline constexpr uintptr_t LocalPlayer = 0x120;
         inline constexpr uintptr_t LocaleId = 0x108;
         inline constexpr uintptr_t MaxPlayers = 0x130;
         inline constexpr uintptr_t MaxZoomDistance = 0x358;
         inline constexpr uintptr_t MaximumSimulationRadius = 0x38c;
         inline constexpr uintptr_t MinZoomDistance = 0x35c;
         inline constexpr uintptr_t ModelInstance = 0x288;
         inline constexpr uintptr_t Mouse = 0x1208;
         inline constexpr uintptr_t NameDisplayDistance = 0x394;
         inline constexpr uintptr_t NeedRegionalFallback = 0x3bb;
         inline constexpr uintptr_t Neutral = 0x3bc;
         inline constexpr uintptr_t PreferredPlayers = 0x134;
         inline constexpr uintptr_t RawJoinData = 0x1a8;
         inline constexpr uintptr_t RespawnTime = 0x138;
         inline constexpr uintptr_t SimulationRadius = 0x398;
         inline constexpr uintptr_t StepIdOffset = 0x39c;
         inline constexpr uintptr_t Team = 0x2c8;
         inline constexpr uintptr_t TeamColor = 0x3a0;
         inline constexpr uintptr_t Teleported = 0x3bd;
         inline constexpr uintptr_t TeleportedIn = 0x3be;
         inline constexpr uintptr_t UseStrafingAnimations = 0x13e;
         inline constexpr uintptr_t User = 0xa8;
         inline constexpr uintptr_t UserId = 0xc0;
         inline constexpr uintptr_t VREnabled = 0x3c0;
         inline constexpr uintptr_t VoiceChatVolume = 0x3ac;
    }

    namespace PlayerConfigurer {
         inline constexpr uintptr_t Pointer = 0x0;
    }

    namespace PlayerDataRecord {
         inline constexpr uintptr_t CreatedTime = 0xd8;
         inline constexpr uintptr_t DefaultRecordName = 0xfc;
         inline constexpr uintptr_t FlushedTime = 0xe0;
         inline constexpr uintptr_t LoadedTime = 0xe8;
         inline constexpr uintptr_t ModifiedTime = 0xf0;
         inline constexpr uintptr_t Writable = 0x100;
    }

    namespace PlayerEmulatorService {
         inline constexpr uintptr_t CustomPoliciesEnabled = 0x11c;
         inline constexpr uintptr_t PlayerEmulationEnabled = 0x11d;
         inline constexpr uintptr_t PseudolocalizationEnabled = 0x11e;
         inline constexpr uintptr_t TextElongationFactor = 0x118;
    }

    namespace PlayerListConfiguration {
         inline constexpr uintptr_t Open = 0xa8;
    }

    namespace PlayerMouse {
         inline constexpr uintptr_t Icon = 0xb8;
         inline constexpr uintptr_t Workspace = 0x140;
    }

    namespace Plugin {
         inline constexpr uintptr_t DisableUIDragDetectorDrags = 0xcc;
         inline constexpr uintptr_t IsDebuggable = 0xcd;
    }

    namespace PointLight {
         inline constexpr uintptr_t Range = 0xc8;
    }

    namespace Pose {
         inline constexpr uintptr_t CFrame = 0xc0;
    }

    namespace PoseBase {
         inline constexpr uintptr_t Weight = 0xb0;
    }

    namespace PostEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
    }

    namespace Primitive {
         inline constexpr uintptr_t AssemblyAngularVelocity = 0xec;
         inline constexpr uintptr_t AssemblyLinearVelocity = 0xe0;
         inline constexpr uintptr_t Flags = 0x1b6;
         inline constexpr uintptr_t Material = 0x0;
         inline constexpr uintptr_t Owner = 0x210;
         inline constexpr uintptr_t Position = 0xd4;
         inline constexpr uintptr_t Rotation = 0xb0;
         inline constexpr uintptr_t Size = 0x1bc;
         inline constexpr uintptr_t Validate = 0x6;
    }

    namespace PrimitiveFlags {
         inline constexpr uintptr_t Anchored = 0x2;
         inline constexpr uintptr_t CanCollide = 0x8;
         inline constexpr uintptr_t CanQuery = 0x20;
         inline constexpr uintptr_t CanTouch = 0x10;
    }

    namespace ProximityPrompt {
         inline constexpr uintptr_t ActionText = 0xa0;
         inline constexpr uintptr_t Enabled = 0x126;
         inline constexpr uintptr_t GamepadKeyCode = 0x10c;
         inline constexpr uintptr_t HoldDuration = 0x110;
         inline constexpr uintptr_t KeyCode = 0x114;
         inline constexpr uintptr_t MaxActivationDistance = 0x118;
         inline constexpr uintptr_t MaxIndicatorDistance = 0x11c;
         inline constexpr uintptr_t ObjectText = 0xc0;
         inline constexpr uintptr_t RequiresLineOfSight = 0x127;
    }

    namespace ProximityPromptService {
         inline constexpr uintptr_t Enabled = 0xd8;
         inline constexpr uintptr_t MaxIndicatorsVisible = 0xd0;
         inline constexpr uintptr_t MaxPromptsVisible = 0xd4;
    }

    namespace PyramidHandleAdornment {
         inline constexpr uintptr_t Height = 0x198;
         inline constexpr uintptr_t Sides = 0x1a0;
    }

    namespace RealtimeMedia {
         inline constexpr uintptr_t AudioInputActive = 0x2a0;
    }

    namespace RenderingTest {
         inline constexpr uintptr_t Description = 0xa8;
         inline constexpr uintptr_t PerfTest = 0x12c;
         inline constexpr uintptr_t RenderingTestFrameCount = 0x124;
         inline constexpr uintptr_t ShouldSkip = 0x12d;
         inline constexpr uintptr_t Ticket = 0xc8;
         inline constexpr uintptr_t Timeout = 0x128;
    }

    namespace RenderJob {
         inline constexpr uintptr_t FakeDataModel = 0x38;
         inline constexpr uintptr_t RealDataModel = 0x1f0;
         inline constexpr uintptr_t RenderView = 0x1e0;
    }

    namespace RenderView {
         inline constexpr uintptr_t DeviceD3D11 = 0x0;
         inline constexpr uintptr_t LightingValid = 0x0;
         inline constexpr uintptr_t SkyValid = 0x0;
         inline constexpr uintptr_t VisualEngine = 0x0;
    }

    namespace ReverbSoundEffect {
         inline constexpr uintptr_t DecayTime = 0xe8;
         inline constexpr uintptr_t Diffusion = 0xf0;
         inline constexpr uintptr_t DryLevel = 0xf4;
         inline constexpr uintptr_t WetLevel = 0xf8;
    }

    namespace RigidConstraint {
         inline constexpr uintptr_t EnableSkinning = 0x158;
    }

    namespace RocketPropulsion {
         inline constexpr uintptr_t Active = 0x2c0;
         inline constexpr uintptr_t CartoonFactor = 0x2a0;
         inline constexpr uintptr_t MaxSpeed = 0x2a4;
         inline constexpr uintptr_t MaxThrust = 0x2a8;
         inline constexpr uintptr_t TargetRadius = 0x2ac;
         inline constexpr uintptr_t ThrustD = 0x2b0;
         inline constexpr uintptr_t ThrustP = 0x2b4;
         inline constexpr uintptr_t TurnD = 0x2b8;
         inline constexpr uintptr_t TurnP = 0x2bc;
    }

    namespace RodConstraint {
         inline constexpr uintptr_t Length = 0x160;
         inline constexpr uintptr_t LimitAngle1 = 0x168;
         inline constexpr uintptr_t LimitsEnabled = 0x170;
         inline constexpr uintptr_t Thickness = 0x16c;
    }

    namespace RolloutValidation {
         inline constexpr uintptr_t AdditionalFluffThree = 0x1dc;
         inline constexpr uintptr_t AdditionalFluffTwo = 0x398;
         inline constexpr uintptr_t CreationVersion = 0x1e0;
         inline constexpr uintptr_t FirstBinaryString = 0xc0;
         inline constexpr uintptr_t FirstSharedExpectedValue = 0xe0;
         inline constexpr uintptr_t FirstSharedString = 0x1c0;
         inline constexpr uintptr_t GenerationStrategy = 0x1e4;
         inline constexpr uintptr_t SecondBinaryExpectedValue = 0x100;
         inline constexpr uintptr_t SecondBinaryString = 0x120;
         inline constexpr uintptr_t SecondSharedExpectedValue = 0x140;
         inline constexpr uintptr_t SecondSharedString = 0x1c8;
         inline constexpr uintptr_t ThirdBinaryExpectedValue = 0x160;
         inline constexpr uintptr_t ThirdBinaryString = 0x180;
         inline constexpr uintptr_t ThirdSharedExpectedValue = 0x1a0;
         inline constexpr uintptr_t ThirdSharedString = 0x1d0;
    }

    namespace RopeConstraint {
         inline constexpr uintptr_t Length = 0x160;
         inline constexpr uintptr_t Thickness = 0x168;
         inline constexpr uintptr_t WinchEnabled = 0x17c;
         inline constexpr uintptr_t WinchForce = 0x16c;
         inline constexpr uintptr_t WinchResponsiveness = 0x170;
         inline constexpr uintptr_t WinchSpeed = 0x174;
         inline constexpr uintptr_t WinchTarget = 0x178;
    }

    namespace RunService {
         inline constexpr uintptr_t HeartbeatFPS = 0xe1;
         inline constexpr uintptr_t HeartbeatTask = 0x6338;
    }

    namespace SafetyService {
         inline constexpr uintptr_t IsCaptureModeForReport = 0xb0;
    }

    namespace ScreenGui {
         inline constexpr uintptr_t ClipToDeviceSafeArea = 0x744;
         inline constexpr uintptr_t DisplayOrder = 0x738;
         inline constexpr uintptr_t IgnoresTitleBarReservation = 0x745;
         inline constexpr uintptr_t OnTopOfCoreBlur = 0x746;
    }

    namespace ScreenshotHud {
         inline constexpr uintptr_t CloseButtonPosition = 0xe0;
    }

    namespace Script {
         inline constexpr uintptr_t ByteCode = 0x0;
         inline constexpr uintptr_t GUID = 0xc0;
         inline constexpr uintptr_t Hash = 0x190;
         inline constexpr uintptr_t Source = 0x178;
    }

    namespace ScriptContext {
         inline constexpr uintptr_t RequireBypass = 0x0;
         inline constexpr uintptr_t ScriptsDisabled = 0xb8;
    }

    namespace ScriptDebugger {
         inline constexpr uintptr_t CurrentLine = 0xb8;
    }

    namespace ScrollingFrame {
         inline constexpr uintptr_t CanvasPosition = 0xa74;
         inline constexpr uintptr_t ScrollBarImageTransparency = 0xa9c;
         inline constexpr uintptr_t ScrollRate = 0xaa4;
         inline constexpr uintptr_t ScrollVelocity = 0xa84;
         inline constexpr uintptr_t ScrollingEnabled = 0xab4;
         inline constexpr uintptr_t SmoothScroll = 0xab5;
    }

    namespace Seat {
         inline constexpr uintptr_t Occupant = 0x208;
    }

    namespace SelectionBox {
         inline constexpr uintptr_t LineThickness = 0x104;
         inline constexpr uintptr_t StudioSelectionBox = 0x10c;
         inline constexpr uintptr_t SurfaceColor3 = 0xf8;
         inline constexpr uintptr_t SurfaceTransparency = 0x108;
    }

    namespace SelectionPointLasso {
         inline constexpr uintptr_t Point = 0xf8;
    }

    namespace SelectionSphere {
         inline constexpr uintptr_t SurfaceColor3 = 0xf8;
         inline constexpr uintptr_t SurfaceTransparency = 0x104;
    }

    namespace SelfViewConfiguration {
         inline constexpr uintptr_t Open = 0xa8;
    }

    namespace ServerScriptService {
         inline constexpr uintptr_t LoadStringEnabled = 0xb8;
    }

    namespace SkateboardController {
         inline constexpr uintptr_t Steer = 0x108;
         inline constexpr uintptr_t Throttle = 0x10c;
    }

    namespace SkateboardPlatform {
         inline constexpr uintptr_t Steer = 0x21c;
         inline constexpr uintptr_t Throttle = 0x220;
    }

    namespace Skin {
         inline constexpr uintptr_t SkinColor = 0xb0;
    }

    namespace Sky {
         inline constexpr uintptr_t MoonAngularSize = 0x234;
         inline constexpr uintptr_t MoonTextureId = 0xb8;
         inline constexpr uintptr_t SkyboxBk = 0xe8;
         inline constexpr uintptr_t SkyboxDn = 0x118;
         inline constexpr uintptr_t SkyboxFt = 0x148;
         inline constexpr uintptr_t SkyboxLf = 0x178;
         inline constexpr uintptr_t SkyboxOrientation = 0x228;
         inline constexpr uintptr_t SkyboxRt = 0x1a8;
         inline constexpr uintptr_t SkyboxUp = 0x1d8;
         inline constexpr uintptr_t StarCount = 0x238;
         inline constexpr uintptr_t SunAngularSize = 0x22c;
         inline constexpr uintptr_t SunTextureId = 0x208;
    }

    namespace SlidingBallConstraint {
         inline constexpr uintptr_t LowerLimit = 0x168;
         inline constexpr uintptr_t MotorMaxAcceleration = 0x16c;
         inline constexpr uintptr_t MotorMaxForce = 0x170;
         inline constexpr uintptr_t Restitution = 0x174;
         inline constexpr uintptr_t ServoMaxForce = 0x178;
         inline constexpr uintptr_t Size = 0x17c;
         inline constexpr uintptr_t Speed = 0x180;
         inline constexpr uintptr_t TargetPosition = 0x184;
         inline constexpr uintptr_t UpperLimit = 0x188;
         inline constexpr uintptr_t Velocity = 0x18c;
    }

    namespace SlimAnimationDataEntity {
         inline constexpr uintptr_t EntityScale = 0xf0;
         inline constexpr uintptr_t Handle = 0x100;
         inline constexpr uintptr_t IsSlimEnabled = 0x10c;
         inline constexpr uintptr_t NumBones = 0x104;
         inline constexpr uintptr_t RootIndex = 0x108;
         inline constexpr uintptr_t SlimReplicationTimestampSec = 0xf8;
    }

    namespace Smoke {
         inline constexpr uintptr_t Color = 0xa8;
         inline constexpr uintptr_t Enabled = 0xc8;
         inline constexpr uintptr_t LocalTransparencyModifier = 0xb4;
         inline constexpr uintptr_t Opacity = 0xb8;
         inline constexpr uintptr_t RiseVelocity = 0xbc;
         inline constexpr uintptr_t Size = 0xc0;
         inline constexpr uintptr_t TimeScale = 0xc4;
    }

    namespace Sound {
         inline constexpr uintptr_t AcousticSimulationEnabled = 0x12c;
         inline constexpr uintptr_t IsPlaying = 0x130;
         inline constexpr uintptr_t Looped = 0x12d;
         inline constexpr uintptr_t PlayOnRemove = 0x12e;
         inline constexpr uintptr_t PlaybackRegion = 0xf0;
         inline constexpr uintptr_t PlaybackSpeed = 0x10c;
         inline constexpr uintptr_t RollOffMaxDistance = 0x110;
         inline constexpr uintptr_t RollOffMinDistance = 0x114;
         inline constexpr uintptr_t SoundGroup = 0xd8;
         inline constexpr uintptr_t SoundId = 0xb8;
         inline constexpr uintptr_t Volume = 0x120;
    }

    namespace SoundEffect {
         inline constexpr uintptr_t Priority = 0xa8;
    }

    namespace SoundGroup {
         inline constexpr uintptr_t Volume = 0xa8;
    }

    namespace SoundService {
         inline constexpr uintptr_t AcousticSimulationEnabled = 0x168;
         inline constexpr uintptr_t DiffractionEnabled = 0x169;
         inline constexpr uintptr_t DistanceFactor = 0x154;
         inline constexpr uintptr_t DopplerScale = 0x158;
         inline constexpr uintptr_t IsNewExpForAudioApiByDefault = 0x16a;
         inline constexpr uintptr_t ListenerCFrame = 0x110;
         inline constexpr uintptr_t OcclusionEnabled = 0x16b;
         inline constexpr uintptr_t RespectFilteringEnabled = 0x16c;
         inline constexpr uintptr_t ReverbEnabled = 0x16d;
         inline constexpr uintptr_t RolloffScale = 0x160;
    }

    namespace Sparkles {
         inline constexpr uintptr_t Enabled = 0xbc;
         inline constexpr uintptr_t LocalTransparencyModifier = 0xb4;
         inline constexpr uintptr_t SparkleColor = 0xa8;
         inline constexpr uintptr_t TimeScale = 0xb8;
    }

    namespace SpawnLocation {
         inline constexpr uintptr_t AllowTeamChangeOnTouch = 0x1e0;
         inline constexpr uintptr_t Duration = 0x1d8;
         inline constexpr uintptr_t Enabled = 0x1e1;
         inline constexpr uintptr_t ForcefieldDuration = 0x1d8;
         inline constexpr uintptr_t Neutral = 0x1e2;
         inline constexpr uintptr_t TeamColor = 0x1dc;
    }

    namespace SpecialMesh {
         inline constexpr uintptr_t MeshId = 0xe8;
         inline constexpr uintptr_t Scale = 0xb4;
    }

    namespace SphereHandleAdornment {
         inline constexpr uintptr_t Radius = 0x198;
    }

    namespace SpotLight {
         inline constexpr uintptr_t Angle = 0xc8;
         inline constexpr uintptr_t Range = 0xd0;
    }

    namespace SpringConstraint {
         inline constexpr uintptr_t Coils = 0x160;
         inline constexpr uintptr_t FreeLength = 0x168;
         inline constexpr uintptr_t LimitsEnabled = 0x184;
         inline constexpr uintptr_t MaxForce = 0x16c;
         inline constexpr uintptr_t MaxLength = 0x170;
         inline constexpr uintptr_t MinLength = 0x174;
         inline constexpr uintptr_t Radius = 0x178;
         inline constexpr uintptr_t Stiffness = 0x17c;
         inline constexpr uintptr_t Thickness = 0x180;
    }

    namespace StarterGui {
         inline constexpr uintptr_t ShowDevelopmentGui = 0x182;
    }

    namespace StarterPlayer {
         inline constexpr uintptr_t AllowCustomAnimations = 0x11c;
         inline constexpr uintptr_t AutoJumpEnabled = 0x11d;
         inline constexpr uintptr_t CameraMaxZoomDistance = 0xcc;
         inline constexpr uintptr_t CameraMinZoomDistance = 0xd0;
         inline constexpr uintptr_t CharacterBreakJointsOnDeath = 0x11e;
         inline constexpr uintptr_t CharacterJumpHeight = 0xd8;
         inline constexpr uintptr_t CharacterJumpPower = 0xdc;
         inline constexpr uintptr_t CharacterMaxSlopeAngle = 0xe0;
         inline constexpr uintptr_t CharacterUseJumpPower = 0x11f;
         inline constexpr uintptr_t CharacterWalkSpeed = 0xe4;
         inline constexpr uintptr_t ClassicDeath = 0x120;
         inline constexpr uintptr_t CreateDefaultPlayerModule = 0x121;
         inline constexpr uintptr_t EnableMouseLockOption = 0x122;
         inline constexpr uintptr_t HealthDisplayDistance = 0x108;
         inline constexpr uintptr_t LoadCharacterAppearance = 0x123;
         inline constexpr uintptr_t NameDisplayDistance = 0x114;
         inline constexpr uintptr_t PlayerModuleStatus = 0x118;
         inline constexpr uintptr_t UserEmotesEnabled = 0x124;
    }

    namespace StateMachineTransitionDefinition {
         inline constexpr uintptr_t Priority = 0xe0;
    }

    namespace StatsItem {
         inline constexpr uintptr_t Value = 0x5e0;
    }

    namespace StudioData {
         inline constexpr uintptr_t EnableScriptCollabByDefaultOnLoad = 0xb8;
    }

    namespace StyleDerive {
         inline constexpr uintptr_t Index = 0xb8;
         inline constexpr uintptr_t Priority = 0xbc;
    }

    namespace StyleQuery {
         inline constexpr uintptr_t IsActive = 0xa0;
    }

    namespace StyleRule {
         inline constexpr uintptr_t Index = 0x160;
         inline constexpr uintptr_t Priority = 0x164;
    }

    namespace SunRaysEffect {
         inline constexpr uintptr_t Enabled = 0xa0;
         inline constexpr uintptr_t Intensity = 0xa8;
         inline constexpr uintptr_t Spread = 0xac;
    }

    namespace SurfaceAppearance {
         inline constexpr uintptr_t AlphaMode = 0x1e0;
         inline constexpr uintptr_t Color = 0x1c8;
         inline constexpr uintptr_t ColorMap = 0xb8;
         inline constexpr uintptr_t ColorMapContent = 0xa8;
         inline constexpr uintptr_t EmissiveMaskContent = 0xe8;
         inline constexpr uintptr_t EmissiveStrength = 0x1e4;
         inline constexpr uintptr_t EmissiveTint = 0x1d4;
         inline constexpr uintptr_t MetalnessMap = 0x118;
         inline constexpr uintptr_t MetalnessMapContent = 0x108;
         inline constexpr uintptr_t NormalMap = 0x148;
         inline constexpr uintptr_t RoughnessMap = 0x178;
         inline constexpr uintptr_t SurfaceSlot = 0x1ec;
    }

    namespace SurfaceGui {
         inline constexpr uintptr_t AlwaysOnTop = 0x85c;
         inline constexpr uintptr_t HorizontalCurvature = 0x83c;
         inline constexpr uintptr_t MaxDistance = 0x844;
         inline constexpr uintptr_t PixelsPerStud = 0x848;
         inline constexpr uintptr_t ToolPunchThroughDistance = 0x854;
         inline constexpr uintptr_t ZOffset = 0x858;
    }

    namespace SurfaceGuiBase {
         inline constexpr uintptr_t Active = 0x74c;
    }

    namespace SurfaceLight {
         inline constexpr uintptr_t Angle = 0xc8;
         inline constexpr uintptr_t Range = 0xd0;
    }

    namespace SwimController {
         inline constexpr uintptr_t AccelerationTime = 0xd0;
         inline constexpr uintptr_t PitchSpeedFactor = 0xd8;
         inline constexpr uintptr_t RollMaxTorque = 0xdc;
         inline constexpr uintptr_t RollSpeedFactor = 0xe0;
    }

    namespace TaskScheduler {
         inline constexpr uintptr_t JobEnd = 0xd0;
         inline constexpr uintptr_t JobName = 0x18;
         inline constexpr uintptr_t JobStart = 0xc8;
         inline constexpr uintptr_t MaxFPS = 0xb0;
         inline constexpr uintptr_t Pointer = 0x8b79128;
    }

    namespace Team {
         inline constexpr uintptr_t BrickColor = 0xa8;
         inline constexpr uintptr_t ChildOrder = 0xa0;
         inline constexpr uintptr_t TeamColor = 0xa8;
    }

    namespace TeleportOptions {
         inline constexpr uintptr_t ShouldReserveServer = 0x120;
    }

    namespace TeleportService {
         inline constexpr uintptr_t CustomizedTeleportUI = 0xb8;
    }

    namespace Terrain {
         inline constexpr uintptr_t GrassLength = 0x1e0;
         inline constexpr uintptr_t MaterialColors = 0x4a8;
         inline constexpr uintptr_t SmoothVoxelsUpgraded = 0x1fa;
         inline constexpr uintptr_t WaterColor = 0x1d0;
         inline constexpr uintptr_t WaterReflectance = 0x1e8;
         inline constexpr uintptr_t WaterTransparency = 0x1ec;
         inline constexpr uintptr_t WaterWaveSize = 0x1f0;
         inline constexpr uintptr_t WaterWaveSpeed = 0x1f4;
    }

    namespace TerrainDetail {
         inline constexpr uintptr_t ColorMapContent = 0xa8;
         inline constexpr uintptr_t EmissiveMaskContent = 0xd8;
         inline constexpr uintptr_t MetalnessMapContent = 0x108;
    }

    namespace TestFailure {
         inline constexpr uintptr_t Line = 0xc0;
    }

    namespace TestResult {
         inline constexpr uintptr_t FailedChecks = 0xe8;
         inline constexpr uintptr_t PassedChecks = 0xec;
    }

    namespace TestRunResult {
         inline constexpr uintptr_t Failed = 0x88;
         inline constexpr uintptr_t Passed = 0x8c;
         inline constexpr uintptr_t Skipped = 0x90;
    }

    namespace TestService {
         inline constexpr uintptr_t AutoRuns = 0x100;
         inline constexpr uintptr_t ExecuteWithStudioRun = 0x101;
         inline constexpr uintptr_t IsPhysicsEnvironmentalThrottled = 0x102;
         inline constexpr uintptr_t NumberOfPlayers = 0xf4;
         inline constexpr uintptr_t TestCount = 0xf8;
         inline constexpr uintptr_t WarnCount = 0xfc;
    }

    namespace TextBox {
         inline constexpr uintptr_t Confidential = 0xf29;
         inline constexpr uintptr_t ContentText = 0xe00;
         inline constexpr uintptr_t HasFocus = 0xf2a;
         inline constexpr uintptr_t LocalizationMatchIdentifier = 0xe20;
         inline constexpr uintptr_t LocalizationMatchedSourceText = 0xe40;
         inline constexpr uintptr_t LocalizedPlaceholderText = 0xe60;
         inline constexpr uintptr_t ManualFocusRelease = 0xf2b;
         inline constexpr uintptr_t MaxVisibleGraphemes = 0xefc;
         inline constexpr uintptr_t MultiLine = 0xf2c;
         inline constexpr uintptr_t OpenTypeFeatures = 0xec8;
         inline constexpr uintptr_t OverlayNativeInput = 0xf2d;
         inline constexpr uintptr_t ShouldEmitReturnEvents = 0xf2f;
         inline constexpr uintptr_t ShouldEmitTabEvents = 0xf30;
         inline constexpr uintptr_t ShouldEmitUpAndDownArrowEvents = 0xf31;
         inline constexpr uintptr_t TextStrokeTransparency = 0xf14;
         inline constexpr uintptr_t TextTransparency = 0xf18;
    }

    namespace TextButton {
         inline constexpr uintptr_t Confidential = 0x1174;
         inline constexpr uintptr_t ContentText = 0x1088;
         inline constexpr uintptr_t LineHeight = 0x1150;
         inline constexpr uintptr_t LocalizationMatchIdentifier = 0x10a8;
         inline constexpr uintptr_t LocalizationMatchedSourceText = 0x10c8;
         inline constexpr uintptr_t OpenTypeFeatures = 0x1130;
         inline constexpr uintptr_t TextStrokeTransparency = 0x1160;
         inline constexpr uintptr_t TextTransparency = 0x1164;
    }

    namespace TextChannel {
         inline constexpr uintptr_t AddPlayersOnJoin = 0xb0;
    }

    namespace TextChannelWindow {
         inline constexpr uintptr_t IsRendering = 0x9b0;
         inline constexpr uintptr_t UseDefaultFont = 0x9b1;
    }

    namespace TextChatMessage {
         inline constexpr uintptr_t ForModeration = 0x2bc;
         inline constexpr uintptr_t IsHiddenMessage = 0x2bd;
         inline constexpr uintptr_t IsHistorical = 0x2be;
         inline constexpr uintptr_t Verified = 0x2bf;
         inline constexpr uintptr_t WasRewritten = 0x2c0;
    }

    namespace TextChatService {
         inline constexpr uintptr_t CreateDefaultCommands = 0x1e3;
         inline constexpr uintptr_t HasSeenDeprecationDialog = 0x1e5;
         inline constexpr uintptr_t IsLegacyChatDisabled = 0x1e6;
    }

    namespace TextGenerator {
         inline constexpr uintptr_t Seed = 0xc0;
         inline constexpr uintptr_t Temperature = 0xc4;
         inline constexpr uintptr_t TopP = 0xc8;
    }

    namespace TextLabel {
         inline constexpr uintptr_t Confidential = 0xef4;
         inline constexpr uintptr_t ContentText = 0xe08;
         inline constexpr uintptr_t LineHeight = 0xed0;
         inline constexpr uintptr_t LocalizationMatchIdentifier = 0xe28;
         inline constexpr uintptr_t LocalizationMatchedSourceText = 0xe48;
         inline constexpr uintptr_t RichText = 0xef5;
         inline constexpr uintptr_t Text = 0xe10;
         inline constexpr uintptr_t TextScaled = 0xef7;
         inline constexpr uintptr_t TextStrokeTransparency = 0xee0;
         inline constexpr uintptr_t TextTransparency = 0xee4;
    }

    namespace TextSource {
         inline constexpr uintptr_t CanSend = 0xe8;
         inline constexpr uintptr_t UserId = 0xe0;
    }

    namespace Texture {
         inline constexpr uintptr_t OffsetStudsU = 0x2d8;
         inline constexpr uintptr_t OffsetStudsV = 0x2dc;
         inline constexpr uintptr_t StudsPerTileU = 0x2e0;
         inline constexpr uintptr_t StudsPerTileV = 0x2e4;
    }

    namespace Textures {
         inline constexpr uintptr_t Decal_Texture = 0x1d0;
         inline constexpr uintptr_t Texture_Texture = 0x1d0;
    }

    namespace ThirdPartyUserService {
         inline constexpr uintptr_t HasActiveUser = 0xb8;
    }

    namespace Tool {
         inline constexpr uintptr_t CanBeDropped = 0x4a8;
         inline constexpr uintptr_t Enabled = 0x4a9;
         inline constexpr uintptr_t Grip = 0x49c;
         inline constexpr uintptr_t ManualActivationOnly = 0x4aa;
         inline constexpr uintptr_t RequiresHandle = 0x4ab;
         inline constexpr uintptr_t TextureId = 0x350;
         inline constexpr uintptr_t ToolTip = 0x458;
         inline constexpr uintptr_t Tooltip = 0x458;
    }

    namespace Torque {
         inline constexpr uintptr_t Torque = 0x160;
    }

    namespace TorsionSpringConstraint {
         inline constexpr uintptr_t Coils = 0x160;
         inline constexpr uintptr_t MaxAngle = 0x168;
         inline constexpr uintptr_t MaxTorque = 0x16c;
         inline constexpr uintptr_t Radius = 0x170;
         inline constexpr uintptr_t Restitution = 0x174;
         inline constexpr uintptr_t Stiffness = 0x178;
    }

    namespace Trail {
         inline constexpr uintptr_t FaceCamera = 0x1d5;
         inline constexpr uintptr_t Transparency = 0xa8;
         inline constexpr uintptr_t WidthScale = 0xe8;
    }

    namespace TremoloSoundEffect {
         inline constexpr uintptr_t Depth = 0xe8;
         inline constexpr uintptr_t Frequency = 0xf0;
    }

    namespace TriangleMeshPart {
         inline constexpr uintptr_t MeshSize = 0x218;
         inline constexpr uintptr_t PCDRequestId = 0x24c;
         inline constexpr uintptr_t UnscaledCofm = 0x224;
         inline constexpr uintptr_t UnscaledVolInertiaDiags = 0x230;
         inline constexpr uintptr_t UnscaledVolInertiaOffDiags = 0x23c;
         inline constexpr uintptr_t UnscaledVolume = 0x250;
    }

    namespace UIAspectRatioConstraint {
         inline constexpr uintptr_t AspectRatio = 0xc0;
    }

    namespace UIBlur {
         inline constexpr uintptr_t Enabled = 0xcc;
         inline constexpr uintptr_t Transparency = 0xc8;
    }

    namespace UICorner {
         inline constexpr uintptr_t BottomLeftRadius = 0xc0;
         inline constexpr uintptr_t BottomRightRadius = 0xc8;
    }

    namespace UIDragDetector {
         inline constexpr uintptr_t DragAxis = 0x198;
         inline constexpr uintptr_t DragRotation = 0x1a8;
         inline constexpr uintptr_t DragUDim2 = 0x158;
         inline constexpr uintptr_t Enabled = 0x1c8;
         inline constexpr uintptr_t MaxDragAngle = 0x1b4;
         inline constexpr uintptr_t MaxDragTranslation = 0x168;
         inline constexpr uintptr_t MinDragAngle = 0x1b8;
         inline constexpr uintptr_t MinDragTranslation = 0x178;
         inline constexpr uintptr_t SelectionModeDragSpeed = 0x188;
         inline constexpr uintptr_t SelectionModeRotateSpeed = 0x1c0;
    }

    namespace UIFlexItem {
         inline constexpr uintptr_t ShrinkRatio = 0xc4;
    }

    namespace UIGradient {
         inline constexpr uintptr_t Offset = 0x130;
         inline constexpr uintptr_t Rotation = 0x138;
    }

    namespace UIGridLayout {
         inline constexpr uintptr_t CellPadding = 0x150;
         inline constexpr uintptr_t CellSize = 0x160;
         inline constexpr uintptr_t FillDirectionMaxCells = 0x180;
    }

    namespace UIPadding {
         inline constexpr uintptr_t PaddingLeft = 0xc0;
         inline constexpr uintptr_t PaddingRight = 0xc8;
         inline constexpr uintptr_t PaddingTop = 0xd0;
    }

    namespace UIPageLayout {
         inline constexpr uintptr_t Animated = 0x16c;
         inline constexpr uintptr_t Circular = 0x16d;
         inline constexpr uintptr_t GamepadInputEnabled = 0x16e;
         inline constexpr uintptr_t Padding = 0x158;
         inline constexpr uintptr_t ScrollWheelInputEnabled = 0x16f;
         inline constexpr uintptr_t TouchInputEnabled = 0x170;
         inline constexpr uintptr_t TweenTime = 0x168;
    }

    namespace UIShadow {
         inline constexpr uintptr_t ShowBehindParent = 0xfa;
         inline constexpr uintptr_t ZIndex = 0xf4;
    }

    namespace UISizeConstraint {
         inline constexpr uintptr_t MaxSize = 0xc0;
    }

    namespace UIStroke {
         inline constexpr uintptr_t BorderOffset = 0xcc;
         inline constexpr uintptr_t Thickness = 0xe4;
         inline constexpr uintptr_t Transparency = 0xe8;
         inline constexpr uintptr_t ZIndex = 0xec;
    }

    namespace UITableLayout {
         inline constexpr uintptr_t FillEmptySpaceColumns = 0x164;
         inline constexpr uintptr_t FillEmptySpaceRows = 0x165;
         inline constexpr uintptr_t Padding = 0x150;
    }

    namespace UITextSizeConstraint {
         inline constexpr uintptr_t MinTextSize = 0xbc;
    }

    namespace UnionOperation {
         inline constexpr uintptr_t AssetId = 0x300;
    }

    namespace UniversalConstraint {
         inline constexpr uintptr_t LimitsEnabled = 0x16c;
         inline constexpr uintptr_t MaxAngle = 0x160;
         inline constexpr uintptr_t Restitution = 0x168;
    }

    namespace UserInputService {
         inline constexpr uintptr_t BottomBarSize = 0xb8;
         inline constexpr uintptr_t LegacyInputEventsEnabled = 0xe0;
         inline constexpr uintptr_t NavBarSize = 0xc0;
         inline constexpr uintptr_t RightBarSize = 0xc8;
         inline constexpr uintptr_t StatusBarSize = 0xd0;
         inline constexpr uintptr_t TouchScreenEnabled = 0xe3;
         inline constexpr uintptr_t WindowInputState = 0x2b0;
    }

    namespace Vector3Value {
         inline constexpr uintptr_t Value = 0xa8;
    }

    namespace VectorForce {
         inline constexpr uintptr_t ApplyAtCenterOfMass = 0x170;
         inline constexpr uintptr_t Force = 0x160;
    }

    namespace VehicleSeat {
         inline constexpr uintptr_t Disabled = 0x22c;
         inline constexpr uintptr_t HeadsUpDisplay = 0x22d;
         inline constexpr uintptr_t MaxSpeed = 0x218;
         inline constexpr uintptr_t SteerFloat = 0x21c;
         inline constexpr uintptr_t ThrottleFloat = 0x220;
         inline constexpr uintptr_t Torque = 0x224;
         inline constexpr uintptr_t TurnSpeed = 0x228;
    }

    namespace VersionControlService {
         inline constexpr uintptr_t ScriptCollabEnabled = 0x108;
    }

    namespace VideoDisplay {
         inline constexpr uintptr_t TileSize = 0xa18;
         inline constexpr uintptr_t VideoTransparency = 0xa4c;
    }

    namespace VideoFrame {
         inline constexpr uintptr_t Looped = 0xa18;
         inline constexpr uintptr_t RollOffMaxDistance = 0xa08;
         inline constexpr uintptr_t RollOffMinDistance = 0xa0c;
         inline constexpr uintptr_t VideoContent = 0x9a0;
         inline constexpr uintptr_t Volume = 0xa14;
    }

    namespace VideoPlayer {
         inline constexpr uintptr_t AutoLoadInStudio = 0x171;
         inline constexpr uintptr_t AutoPlayInStudio = 0x172;
         inline constexpr uintptr_t IsPlaying = 0x173;
         inline constexpr uintptr_t PlaybackSpeed = 0x168;
         inline constexpr uintptr_t PlayingReplicating = 0x170;
         inline constexpr uintptr_t VideoContent = 0x128;
         inline constexpr uintptr_t Volume = 0x16c;
    }

    namespace ViewportFrame {
         inline constexpr uintptr_t CameraCFrame = 0x9b0;
         inline constexpr uintptr_t CameraFieldOfView = 0xa10;
         inline constexpr uintptr_t IsMirrored = 0xa18;
    }

    namespace VisualEngine {
         inline constexpr uintptr_t Dimensions = 0xb10;
         inline constexpr uintptr_t FakeDataModel = 0xaf0;
         inline constexpr uintptr_t Pointer = 0x8656e40;
         inline constexpr uintptr_t RenderView = 0xc30;
         inline constexpr uintptr_t ViewMatrix = 0x1b0;
    }

    namespace VisualizationModeCategory {
         inline constexpr uintptr_t Enabled = 0xc0;
    }

    namespace VoiceChatService {
         inline constexpr uintptr_t EnableDefaultVoice = 0x1f4;
         inline constexpr uintptr_t UseNewAudioApi = 0x1f5;
         inline constexpr uintptr_t UseNewControlPaths = 0x1f6;
         inline constexpr uintptr_t UseNewJoinFlow = 0x1f7;
         inline constexpr uintptr_t UseStreamSwitching = 0x1f8;
         inline constexpr uintptr_t VoiceChatEnabledForPlaceOnRcc = 0x1f9;
         inline constexpr uintptr_t VoiceChatEnabledForUniverseOnRcc = 0x1fa;
    }

    namespace VRService {
         inline constexpr uintptr_t AvatarGestures = 0x124;
         inline constexpr uintptr_t DidPointerHit = 0x125;
         inline constexpr uintptr_t FadeOutViewOnCollision = 0x126;
         inline constexpr uintptr_t PointerHitCFrame = 0xd8;
         inline constexpr uintptr_t QuestASWState = 0x127;
         inline constexpr uintptr_t QuestDisplayRefreshRate = 0x11c;
         inline constexpr uintptr_t VRDeviceAvailable = 0x128;
         inline constexpr uintptr_t VRDeviceName = 0xb8;
         inline constexpr uintptr_t VREnabled = 0x129;
    }

    namespace Weld {
         inline constexpr uintptr_t EnableSkinning = 0x178;
         inline constexpr uintptr_t Part0 = 0x108;
         inline constexpr uintptr_t Part1 = 0x118;
    }

    namespace WeldConstraint {
         inline constexpr uintptr_t Enabled = 0xc8;
         inline constexpr uintptr_t Part0 = 0xa8;
         inline constexpr uintptr_t Part1 = 0xb8;
    }

    namespace WindowInputState {
         inline constexpr uintptr_t CapsLock = 0x40;
         inline constexpr uintptr_t CurrentTextBox = 0x48;
    }

    namespace Wire {
         inline constexpr uintptr_t SourceName = 0xa8;
         inline constexpr uintptr_t TargetName = 0xc8;
    }

    namespace WireframeHandleAdornment {
         inline constexpr uintptr_t Scale = 0x198;
    }

    namespace Workspace {
         inline constexpr uintptr_t CurrentCamera = 0x4a8;
         inline constexpr uintptr_t DistributedGameTime = 0x4c8;
         inline constexpr uintptr_t ReadOnlyGravity = 0x9c8;
         inline constexpr uintptr_t World = 0x400;
    }

    namespace World {
         inline constexpr uintptr_t AirProperties = 0x238;
         inline constexpr uintptr_t FallenPartsDestroyHeight = 0x218;
         inline constexpr uintptr_t Gravity = 0x224;
         inline constexpr uintptr_t Primitives = 0x2c8;
         inline constexpr uintptr_t worldStepsPerSec = 0x740;
    }

    namespace WorldModel {
         inline constexpr uintptr_t UseWorkspaceCollisionGroups = 0x470;
    }

    namespace WorldRoot {
         inline constexpr uintptr_t GravityDirection = 0x378;
         inline constexpr uintptr_t SimulationRate = 0x394;
         inline constexpr uintptr_t Wind = 0x398;
    }

    namespace WrapLayer {
         inline constexpr uintptr_t BindOffset = 0x300;
         inline constexpr uintptr_t Enabled = 0x398;
         inline constexpr uintptr_t MaxSize = 0x36c;
         inline constexpr uintptr_t Offset = 0x378;
         inline constexpr uintptr_t Order = 0x38c;
         inline constexpr uintptr_t Puffiness = 0x390;
         inline constexpr uintptr_t ReferenceMeshContent = 0x2a0;
         inline constexpr uintptr_t ShrinkFactor = 0x394;
    }

    namespace WrapTarget {
         inline constexpr uintptr_t Color = 0x2a0;
         inline constexpr uintptr_t Stiffness = 0x2b0;
    }

    namespace WrapTextureTransfer {
         inline constexpr uintptr_t UVMinBound = 0xd8;
    }
}
