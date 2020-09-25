//
//  WCMacroUILayout.h
//  WCMacroKit
//
//  Created by wesley_chen on 2020/9/25.
//

#ifndef WCMacroUILayout_h
#define WCMacroUILayout_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - UI

#pragma mark > Fixed Value

// use for initializing frame/size/point when change it afterward
#ifndef UNSPECIFIED
#define UNSPECIFIED 0
#endif

#pragma mark > Frame

/**
 Set width and height of a frame

 @param frame the original frame
 @param newWidth the new width. If not change, set it to NAN
 @param newHeight the new height. If not change, set it to NAN
 @return the new frame
 @discussion Use FrameSet macro in WCViewTool instead.
 */
#define FrameSetSize(frame, newWidth, newHeight) ({ \
CGRect __internal_frame = (frame); \
if (!isnan((newWidth))) { \
    __internal_frame.size.width = (newWidth); \
} \
if (!isnan((newHeight))) { \
    __internal_frame.size.height = (newHeight); \
} \
__internal_frame; \
})

/**
Set x and y of a frame

@param frame the original frame
@param newX the new x. If not change, set it to NAN
@param newY the new y. If not change, set it to NAN
@return the new frame
@discussion Use FrameSet macro in WCViewTool instead.
*/
#define FrameSetOrigin(frame, newX, newY) ({ \
CGRect __internal_frame = (frame); \
if (!isnan((newX))) { \
    __internal_frame.origin.x = (newX); \
} \
if (!isnan((newY))) { \
    __internal_frame.origin.y = (newY); \
} \
__internal_frame; \
})

#pragma mark > UIEdgeInsets

#define UIEdgeInsetsSet(insets, newTop, newLeft, newBottom, newRight) \
({ \
UIEdgeInsets __insets = insets; \
if (!isnan((newTop))) { \
    __insets = UIEdgeInsetsMake(newTop, __insets.left, __insets.bottom, __insets.right); \
} \
if (!isnan((newLeft))) { \
    __insets = UIEdgeInsetsMake(__insets.top, newLeft, __insets.bottom, __insets.right); \
} \
if (!isnan((newBottom))) { \
    __insets = UIEdgeInsetsMake(__insets.top, __insets.left, newBottom, __insets.right); \
} \
if (!isnan((newRight))) { \
    __insets = UIEdgeInsetsMake(__insets.top, __insets.left, __insets.bottom, newRight); \
} \
\
__insets; \
});

#pragma mark > CGSize

/**
 Get new size with width and height scaled by the same ratio

 @param size the original size
 @param scale the scale ratio
 @return the new size
 */
#define CGSizeScaled(size, scale) (CGSizeMake((size).width * (scale), (size).height * (scale)))

#endif /* WCMacroUILayout_h */
