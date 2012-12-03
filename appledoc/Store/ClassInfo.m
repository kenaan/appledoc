//
//  ClassInfo.m
//  appledoc
//
//  Created by Tomaž Kragelj on 4/12/12.
//  Copyright (c) 2012 Tomaz Kragelj. All rights reserved.
//

#import "Objects.h"
#import "ClassInfo.h"

@implementation ClassInfo

- (NSString *)uniqueObjectID {
	return self.nameOfClass;
}

- (NSString *)objectCrossRefPathTemplate {
	return [NSString stringWithFormat:@"$CLASSES/%@.$EXT", self.uniqueObjectID];
}

@end

#pragma mark - 

@implementation ClassInfo (Logging)

- (NSString *)description {
	if (!self.nameOfClass) return @"class";
	return [NSString gb_format:@"@interface %@ w/ %@", [self uniqueObjectID], [super description]];
}

- (NSString *)debugDescription {
	NSMutableString *result = [self descriptionStringWithComment];
	[result appendFormat:@"@interface %@", self.nameOfClass];
	if (self.nameOfSuperClass) [result appendFormat:@" : %@", self.nameOfSuperClass];
	[result appendString:[super debugDescription]];
	return result;
}

@end
