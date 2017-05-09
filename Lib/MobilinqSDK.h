//
//  MobilinqSDK.h
//  MobilinqSDK
//
//  Created by arik halperin on 09/05/2017.
//  Copyright © 2017 arik halperin. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for MobilinqSDK.
FOUNDATION_EXPORT double MobilinqSDKVersionNumber;

//! Project version string for MobilinqSDK.
FOUNDATION_EXPORT const unsigned char MobilinqSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MobilinqSDK/PublicHeader.h>

@interface MobilinqVideoView : UIView
@property(nonatomic,readonly) UIView *webrtcView;
@end


@protocol RoomConnectionDelegate <NSObject>
-(void)onCallConnected:(NSUUID *)callId;
-(void)onCallDisconnected:(NSUUID *)callId;
-(void)onHold:(NSUUID *)callId;
-(void)onUnhold:(NSUUID *)callId;
@end


typedef NS_ENUM(NSInteger,CameraType) {
    BACK_CAMERA,
    FRONT_CAMERA
};

typedef NS_ENUM(NSInteger, VideoMode) {
    VIDEO_OFF,
    VIDEO_LOCAL_REMOTE,
    VIDEO_LOCAL,
    VIDEO_REMOTE
};

typedef NS_ENUM(NSInteger, UserType) {
    VIEWER,
    BROADCASTER
};

typedef NS_ENUM(NSInteger, AudioRoute) {
    BLUETOOTH,
    SPEAKER,
    EARPIECE
};


@interface MobilinqSDK : NSObject
+(id) sharedInstance;
+(MobilinqSDK *)getInstance;
-(void)initializeSDK: (NSString *)serverUrl token:(NSString *)token;
-(void)deinitializeSDK;
-(VideoMode)getVideoMode:(NSUUID *)callId;
-(NSUUID *)connectToRoom: (NSString *)roomId userId:(NSString *)roomid userType:(UserType)type videoMode:(VideoMode)videoMode localVideoView:(MobilinqVideoView *)localVideoView remoteVideoView:(MobilinqVideoView *)remoteVideoView connectionDelegate:(id<RoomConnectionDelegate>) delegate;
-(void)disconnectFromRoom: (NSUUID *)callId;
-(void)holdCall:(NSUUID *)callId;
-(void)unholdCall:(NSUUID *)callId;
-(void)setCamera:(CameraType)camera;
-(NSArray *)getAudioRoutes;
-(void)setAudioRoute:(AudioRoute)route;
-(void)mute;
-(void)unmute;
-(void)setVideoMode:(NSUUID *)uuid videoMode:(VideoMode)videoMode;
@end
