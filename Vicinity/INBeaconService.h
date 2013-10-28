//
//  INBlueToothService.h
//  Vicinity
//
//  Created by Ben Ford on 10/28/13.
//  Copyright (c) 2013 Instrument. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    INDetectorRangeUnknown = 0,
    INDetectorRangeFar,
    INDetectorRangeNear,
    INDetectorRangeImmediate,
} INDetectorRange;

#define SINGLETON_IDENTIFIER @"CB284D88-5317-4FB4-9621-C5A3A49E6155"

@class INBeaconService;
@protocol INBeaconServiceDelegate <NSObject>
- (void)service:(INBeaconService *)service foundDeviceWithRange:(INDetectorRange)range;
@end

@interface INBeaconService : NSObject

- (id)initWithIdentifier:(NSString *)theIdentifier;

@property (nonatomic, weak) id<INBeaconServiceDelegate> delegate;

+ (INBeaconService *)singleton;

- (void)startDetecting;
- (void)stopDetecting;

- (void)startBroadcasting;
- (void)stopBroadcasting;
@end