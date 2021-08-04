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
#define FrameSetSize(frame_, newWidth_, newHeight_) \
frame_ = ({ \
    CGRect __internal_frame = (frame_); \
    if (!isnan((newWidth_))) { \
        __internal_frame.size.width = (newWidth_); \
    } \
    if (!isnan((newHeight_))) { \
        __internal_frame.size.height = (newHeight_); \
    } \
    __internal_frame; \
});

/**
 Set x and y of a frame

 @param frame the original frame
 @param newX the new x. If not change, set it to NAN
 @param newY the new y. If not change, set it to NAN
 @return the new frame
 @discussion Use FrameSet macro in WCViewTool instead.
*/
#define FrameSetOrigin(frame_, newX_, newY_) \
frame_ = ({ \
    CGRect __internal_frame = (frame_); \
    if (!isnan((newX_))) { \
        __internal_frame.origin.x = (newX_); \
    } \
    if (!isnan((newY_))) { \
        __internal_frame.origin.y = (newY_); \
    } \
    __internal_frame; \
});

/**
 Set cx and cy of the center

 @param center_ the original center
 @param newCx_ the new cx. If not change, set it to NAN
 @param newCy_ the new cy. If not change, set it to NAN
 @return the new frame
*/
#define FrameSetCenter(center_, newCx_, newCy_) \
center_ = ({ \
    CGPoint __internal_center = (center_); \
    if (!isnan((newCx_))) { \
        __internal_center.x = (newCx_); \
    } \
    if (!isnan((newCy_))) { \
        __internal_center.y = (newCy_); \
    } \
    __internal_center; \
});

#pragma mark > UIEdgeInsets

#define UIEdgeInsetsSet(insets_, newTop_, newLeft_, newBottom_, newRight_) \
insets_ = ({ \
UIEdgeInsets __insets = insets_; \
if (!isnan((newTop_))) { \
    __insets = UIEdgeInsetsMake(newTop_, __insets.left, __insets.bottom, __insets.right); \
} \
if (!isnan((newLeft_))) { \
    __insets = UIEdgeInsetsMake(__insets.top, newLeft_, __insets.bottom, __insets.right); \
} \
if (!isnan((newBottom_))) { \
    __insets = UIEdgeInsetsMake(__insets.top, __insets.left, newBottom_, __insets.right); \
} \
if (!isnan((newRight_))) { \
    __insets = UIEdgeInsetsMake(__insets.top, __insets.left, __insets.bottom, newRight_); \
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
