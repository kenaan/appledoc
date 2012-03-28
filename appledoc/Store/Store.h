//
//  Store.h
//  appledoc
//
//  Created by Tomaž Kragelj on 3/19/12.
//  Copyright (c) 2012 Tomaz Kragelj. All rights reserved.
//

@class PKToken;

/** The main data store for the application.
 
 The store contains all objects parsed from input files. It's designed as the central object for passing data around various components.
 */
@interface Store : NSObject
@end

/** Store category declaring API for registering data.
 */
@interface Store (Registrations)

#pragma mark - Classes, categories and protocols

- (void)beginClassWithName:(NSString *)name derivedFromClassWithName:(NSString *)derived;
- (void)beginExtensionForClassWithName:(NSString *)name;
- (void)beginCategoryWithName:(NSString *)category forClassWithName:(NSString *)name;
- (void)beginProtocolWithName:(NSString *)name;
- (void)appendAdoptedProtocolWithName:(NSString *)name;

#pragma mark - Methods and properties

- (void)beginPropertyDefinition;
- (void)beginPropertyAttributes;
- (void)appendPropertyName:(NSString *)name;

#pragma mark - General objects

- (void)beginTypeDefinition;
- (void)appendType:(NSString *)type;

#pragma mark - Finalizing registrations

- (void)endCurrentObject;
- (void)cancelCurrentObject;

#pragma mark - General information

@property (nonatomic, strong) PKToken *currentSourceInfo;

@end