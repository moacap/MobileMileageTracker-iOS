//
//  MTObjectStore.h
//  mobilemileagetracker
//
//  Created by Chris Ballinger on 9/30/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RestKit/RestKit.h>
#import "MTAPIObject.h"
#import "MTTrip.h"

#define kObjectsLoadedNotificationName @"ObjectsLoadedNotification"


@interface MTObjectStore : NSObject <RKObjectLoaderDelegate>
{
    NSMutableDictionary *deviceStore;
    NSMutableDictionary *tripStore;
    NSMutableDictionary *locationStore;
    NSMutableDictionary *objectStore;
    RKObjectManager *objectManager;
}

+ (MTObjectStore*)sharedInstance; // Singleton method

-(void)addObject:(MTAPIObject*)object;
-(void)addObjects:(NSArray*)objects;
-(void)removeObject:(MTAPIObject*)object;
-(MTAPIObject*)getObjectForURI:(NSString*)URI;

-(NSDictionary*)getDevices;
-(NSDictionary*)getTrips;
-(NSDictionary*)getLocations;
-(NSDictionary*)getObjects;
-(NSArray*)locationsForTrip:(MTTrip*)trip;

+(NSArray*)cachedObjectsForResourcePath:(NSString*)resourcePath;

@property (nonatomic, retain) RKObjectManager *objectManager;


@end
