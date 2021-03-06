//
//  PBChangedFile.h
//  GitX
//
//  Created by Pieter de Bie on 22-09-08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBGitRepository.h"

typedef enum {
	NEW,
	MODIFIED,
	DELETED
} PBChangedFileStatus;

@interface PBChangedFile : NSObject {
	NSString *path;
	BOOL hasCachedChanges;
	BOOL hasUnstagedChanges;

	// Index and HEAD stuff, to be used to revert changes
	NSString *commitBlobSHA;
	NSString *commitBlobMode;

	PBChangedFileStatus status;
}


@property (copy) NSString *path, *commitBlobSHA, *commitBlobMode;
@property (assign) PBChangedFileStatus status;
@property (assign) BOOL hasCachedChanges;
@property (assign) BOOL hasUnstagedChanges;

- (NSImage *)icon;
- (NSString *)indexInfo;

- (id) initWithPath:(NSString *)p;
@end
