//
//  WCMacroKit.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroKit_h
#define WCMacroKit_h

#import "WCMacroColor.h"
#import "WCMacroVersion.h"
#import "WCMacroLog.h"
#import "WCMacroBlock.h"
#import "WCMacroDelegate.h"
#import "WCMacroAssert.h"

// String
#pragma mark - String

#pragma mark > String conversion

// BOOL to string
#define STR_OF_BOOL(yesOrNo)     ((yesOrNo) ? @"YES" : @"NO")
// property name to string
#define STR_OF_PROP(property)    (NSStringFromSelector(@selector(property)))
// literal JSON c string to NSString
// @see https://stackoverflow.com/a/14293615
#define STR_OF_JSON(...) @#__VA_ARGS__

#pragma mark > String modidication

// Catenate two strings
#define STR_CATENATE(str1, str2) ([NSString stringWithFormat:@"%@%@", str1, str2])

#pragma mark > String checking
// Is a string and not empty
#define STR_IF_NOT_EMPTY(str)    ([str isKindOfClass:[NSString class]] && str.length)

// Is a string and empty
#define STR_IF_EMPTY(str)        ([str isKindOfClass:[NSString class]] && str.length == 0)

#pragma mark > String size calculation

// calculate size of single line string
// @see MBProgressHUD
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
    #define STR_SIZE_OF_SINGLELINE(text, font)  [text length] > 0 ? [text sizeWithAttributes:@{ NSFontAttributeName: font }] : CGSizeZero;
#else
    #define STR_SIZE_OF_SINGLELINE(text, font)  [text length] > 0 ? [text sizeWithFont:font] : CGSizeZero;
#endif

// calculate size of multiple lines string
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
    #define STR_SIZE_OF_MULTILINE(text, font, maxSize, mode)                                    \
        [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                               options:(NSStringDrawingUsesLineFragmentOrigin)  \
                                            attributes:@{ NSFontAttributeName: font }           \
                                               context:nil].size                                \
                          : CGSizeZero;
#else
    #define STR_SIZE_OF_MULTILINE(text, font, maxSize, mode)    \
        [text length] > 0 ? [text sizeWithFont:font             \
                             constrainedToSize:maxSize          \
                                 lineBreakMode:mode]            \
                          : CGSizeZero;
#endif

// calculate size of multiple lines string with font parameter
// @note iOS 7+
#define XXX_STR_SIZE_OF_MULTILINE(text, font, maxSize)                                      \
    [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                           options:(NSStringDrawingUsesLineFragmentOrigin)  \
                                        attributes:@{ NSFontAttributeName: font }           \
                                           context:nil].size                                \
                      : CGSizeZero;

// calculate size of multiple lines string with attr parameter
// @note iOS 7+
#define XXX_STR_SIZE_OF_MULTILINE2(text, maxSize, attr)                                     \
    [text length] > 0 ? [text boundingRectWithSize:maxSize                                  \
                                           options:(NSStringDrawingUsesLineFragmentOrigin)  \
                                        attributes:attr                                     \
                                           context:nil].size                                \
                      : CGSizeZero;

#pragma mark - Fixed Value

// use for initializing frame/size/point when change it afterward
#ifndef UNSPECIFIED
#define UNSPECIFIED 0
#endif

// Debug
#pragma mark - Debug

// DEBUG_UI
#ifndef DEBUG_UI
#define DEBUG_UI  1
#endif

// WCLog
#if DEBUG_LOG
#   define WCLog(fmt, ...) { NSLog((@"[ApolloSDK] " fmt), ## __VA_ARGS__); }
#else
#   define WCLog(fmt, ...)
#endif



// Short Code (Others)
#pragma mark - Short Code (Others)

// NSPredicate
#define NSPREDICATE(expression)   ([NSPredicate predicateWithFormat:@"SELF MATCHES %@", expression])

// NSIndexPath
#define NSINDEXPATH(section, row) ([NSIndexPath indexPathForRow:row inSection:section])

// @sa http://stackoverflow.com/questions/11079157/objc-preprocessor-nsstring-macro
// Synthesize Associated Objects
#define SYNTHESIZE_ASSOCIATED_OBJ(getterName, setterName, type)                                                 \
- (void)setterName:(type)object {                                                                               \
    if (object) {                                                                                               \
        objc_setAssociatedObject(self, @selector(getterName), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);       \
    }                                                                                                           \
}                                                                                                               \
- (type)getterName {                                                                                            \
    return objc_getAssociatedObject(self, @selector(getterName));                                               \
}

// Synthesize Associated Primitives
// @sa https://github.com/itsthejb/ObjcAssociatedObjectHelpers/blob/develop/ObjcAssociatedObjectHelpers/ObjcAssociatedObjectHelpers.h
#define SYNTHESIZE_ASSOCIATED_PRIMITIVE(getterName, setterName, type)                                           \
- (void)setterName:(type)value {                                                                                \
    NSValue *nsValue = [NSValue value:&value withObjCType:@encode(type)];                                       \
    objc_setAssociatedObject(self, @selector(getterName), nsValue, OBJC_ASSOCIATION_RETAIN_NONATOMIC);          \
}                                                                                                               \
- (type)getterName {                                                                                            \
    type value;                                                                                                 \
    memset(&value, 0, sizeof(type));                                                                            \
    NSValue *nsValue = objc_getAssociatedObject(self, @selector(getterName));                                   \
    [nsValue getValue:&value];                                                                                  \
    return value;                                                                                               \
}

// Get parent view controller from UIView
#define UIViewResideInUIViewController(__view) ({                               \
    UIViewController *parentViewController = nil;                               \
    UIResponder *__responder = __view;                                          \
    while ([__responder isKindOfClass:[UIView class]]) {                        \
        if ([__responder isKindOfClass:[UIViewController class]]) { break; }    \
        __responder = [__responder nextResponder];                              \
    }                                                                           \
    if ([__responder isKindOfClass:[UIViewController class]]) {                 \
        parentViewController = (UIViewController *)__responder;                 \
    }                                                                           \
    parentViewController;                                                       \
})

// Get parent window from UIView
#define ODK_UIViewResideInUIWindow(__view) ({                           \
    UIWindow *parentWindow = nil;                                       \
    UIResponder *__responder = __view;                                  \
    while ([__responder isKindOfClass:[UIView class]]                   \
        || [__responder isKindOfClass:[UIViewController class]]) {      \
        if ([__responder isKindOfClass:[UIWindow class]]) { break; }    \
        __responder = [__responder nextResponder];                      \
    }                                                                   \
    if ([__responder isKindOfClass:[UIWindow class]]) {                 \
        parentWindow = (UIWindow *)__responder;                         \
    }                                                                   \
    parentWindow;                                                       \
})

// Get status bar height
#define STATUS_BAR_H            (CGRectGetHeight([UIApplication sharedApplication].statusBarFrame))
// Get nav bar height
#define NAV_BAR_H               (CGRectGetHeight(self.navigationController.navigationBar.frame))

/// Alert some tips
// @warning use only in ViewController context
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

#define ALERT_TIP(title, msg, cancel) \
\
do { \
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:(title) message:(msg) preferredStyle:UIAlertControllerStyleAlert]; \
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:(cancel) style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) { \
        [alert dismissViewControllerAnimated:YES completion:nil]; \
    }]; \
    [alert addAction:okAction]; \
    [self presentViewController:alert animated:YES completion:nil]; \
} while (0)

#else // __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

#define ALERT_TIP(title, msg, cancel) \
\
do { \
    if ([UIAlertController class]) { \
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:(title) message:(msg) preferredStyle:UIAlertControllerStyleAlert]; \
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:(cancel) style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) { \
            [alert dismissViewControllerAnimated:YES completion:nil]; \
        }]; \
        [alert addAction:okAction]; \
        [self presentViewController:alert animated:YES completion:nil]; \
    } \
    else { \
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:(title) message:(msg) delegate:nil cancelButtonTitle:(cancel) otherButtonTitles:nil]; \
        [alert show]; \
    } \
} while (0)

#endif // __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

#pragma mark - Check Device Model

// http://stackoverflow.com/a/13156390/4794665
#define IS_IPAD             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA           ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH        ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT       ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH   (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH   (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5         (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6         (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P        (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
// @see https://stackoverflow.com/questions/46196964/detect-iphone-x-with-a-macro
#define IS_IPHONE_X         (IS_IPHONE && SCREEN_MAX_LENGTH == 812.0)
#define IS_IPAD_PRO         (IS_IPAD && SCREEN_MAX_LENGTH == 1366.0)

#pragma mark NSDictionary

/**
 *  NSMutableDictionary calls setObject:forKey: method more safely
 */
#ifndef NSDICTIONARY_M_SAFE_SET
#define NSDICTIONARY_M_SAFE_SET(mutableDictionary, key, value) \
    do {                                                       \
        if (mutableDictionary && key && value) {               \
            [mutableDictionary setObject:value forKey:key];    \
        }                                                      \
    } while (0)

#endif /* NSDICTIONARY_M_SAFE_SET */

#ifndef NSDICTIONARY_M_SAFE_ADD_ENTRIES
#define NSDICTIONARY_M_SAFE_ADD_ENTRIES(mutableDictionary, dictionary) \
    do {                                                               \
        if (mutableDictionary && dictionary) {                         \
            [mutableDictionary addEntriesFromDictionary:dictionary];   \
        }                                                              \
    } while (0)

#endif /* NSDICTIONARY_M_SAFE_ADD_ENTRIES */

#pragma mark NSArray

/*!
 *  Replace elements of NSMutableArray
 *
 *  @param mutableArray the mutable array
 *  @param index        the index
 *  @param value        the value
 */
#ifndef NSARRAY_M_SAFE_SET
#define NSARRAY_M_SAFE_SET(mutableArray, index, value)                    \
    do {                                                                  \
        if (mutableArray && 0 <= index && index < [mutableArray count]) { \
            mutableArray[index] = value;                                  \
        }                                                                 \
    } while (0)

#endif /* NSARRAY_M_SAFE_SET */


#ifndef NSARRAY_M_SAFE_ADD
#define NSARRAY_M_SAFE_ADD(mutableArray, value) \
    do {                                        \
        if (mutableArray && value) {            \
            [mutableArray addObject:value];     \
        }                                       \
    } while (0)

#endif /* NSARRAY_M_SAFE_ADD */

/*!
 *  Get value at index of NSArray
 *
 *  @param array the array
 *  @param index the index
 *
 *  @return the value at index. If nil, when index out of bound
 */
#ifndef NSARRAY_SAFE_GET
#define NSARRAY_SAFE_GET(array, index)                      \
    ({                                                      \
        id value = nil;                                     \
        if (array && 0 <= index && index < [array count]) { \
            value = [array objectAtIndex:index];            \
        }                                                   \
        value;                                              \
    })

#endif /* NSARRAY_SAFE_GET */

#pragma mark Thread

/**
 使用double check nil策略，实现线程安全的lazy getter方法

 @param tempVar 临时变量
 @param instanceVar 实例变量（不能使用self.var形式，而使用_var）
 @param ... 初始化实例变量的代码（可以不赋值临时变量）
 @return tempVar
 
 @note 使用...是因为可能存在逗号`,`的情况，宏会当成逗号作为参数分隔符，导致编译出错
 @see https://stackoverflow.com/a/35999754
 */
#define THREAD_SAFE_LAZY_GETTER_BODY(tempVar, instanceVar, ...)  \
    id tempVar = instanceVar;                                                   \
    if (tempVar == nil) {                                                       \
        @synchronized (self) {                                                  \
            tempVar = instanceVar;                                              \
            if (tempVar == nil) {                                               \
                __VA_ARGS__                                                     \
                tempVar = instanceVar;                                          \
            }                                                                   \
        }                                                                       \
    }                                                                           \
    return tempVar;

#pragma mark - CocoaPod Macro

// Specify Pod (e.g. pod name, pod version)
// TODO: change `OPS` or `ops` to your own pod prefix
#ifndef OPS_PodName
#define OPS_PodName     @"ONEPassportSDK"
#endif

#ifndef OPS_PodVersion
#define OPS_PodVersion  @"0.1.81"
#endif

// Add prefix for category methods
// OPS_PREFIXABLE = 1, enable prefix
// OPS_PREFIXABLE = 0, disable prefix
#define OPS_PREFIXABLE 1
#if OPS_PREFIXABLE

// TODO: configure OPS_PREFIX_NAME here
// @sa http://stackoverflow.com/questions/1489932/how-to-concatenate-twice-with-the-c-preprocessor-and-expand-a-macro-as-in-arg
#   define OPS_PREFIX_NAME          ops
#   define OPS_CATENATE(x, y)       x ## _ ## y
#   define OPS_EVALUATOR(x, y)      OPS_CATENATE(x, y)
#   define ops_prefix(method)       OPS_EVALUATOR(OPS_PREFIX_NAME, method)

#else

#   define ops_prefix(method)  method

#endif /* OPS_PREFIXABLE */


#pragma mark

// Screen Width
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH  ([[UIScreen mainScreen] bounds].size.width)
#endif

// Screen Height
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#endif

// nil convertor
// @warning Only use NILABLE wrap values of literal NSDictionary
#define NILABLE(var)                                                                                        \
    ({                                                                                                      \
        id ret;                                                                                             \
        static NSString *__nilString__ = @"(null)";                                                         \
        if (var == nil) {                                                                                   \
            ret = __nilString__;                                                                            \
        }                                                                                                   \
        else if ([var isKindOfClass:[NSString class]] && [(NSString *)var isEqualToString:__nilString__]) { \
            ret = nil;                                                                                      \
        }                                                                                                   \
        else {                                                                                              \
            ret = var;                                                                                      \
        }                                                                                                   \
        ret;                                                                                                \
    })

// nil check
#define NULLABLE(var) ((var) != nil ? (var) : [NSNull null])

/**
 *  file name
 *
 *  @see http://lists.apple.com/archives/xcode-users/2005/Dec/msg00707.html
 */
#ifndef __FILE_NAME__
#define __FILE_NAME__ ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1)
#endif

#pragma mark - Breakpoint

#define PauseOnThisLineWhenAddedExceptionBreakpoint(shouldPause) \
@try { \
    if (shouldPause) { \
        [NSException raise:@"Assert Exception" format:@""]; \
    } \
} \
@catch (NSException *exception) {}

#pragma mark - Redefinition of System Macro

// 使 NSAssert 只进入断点，之后可以继续运行，而不会杀死程序
// TODO: 需要重新修改
//#undef NSAssert
//#define NSAssert(condition, frmt, ...)                                      \
//    do {                                                                    \
//        @try {                                                              \
//            if (!(condition)) {                                             \
//                NSString *text = @"Assert Exception: ";                     \
//                text = [text stringByAppendingFormat:frmt, ## __VA_ARGS__]; \
//                NSLog(@"%@", text);                                         \
//                [NSException raise:nil format:nil];                         \
//            }                                                               \
//        } @catch (NSException *exception) {                                 \
//        }                                                                   \
//    } while (0);


// Deprecated
#pragma mark - Deprecated

/// Make alignedView aligned center vertically with referencedView
/// 竖直居中对齐
#define WCAlignCenterVertically(alignedView, referencedView)   (CGPointMake(alignedView.center.x, referencedView.center.y))

/// Make alignedView aligned center horizontally with referencedView
/// 水平居中对齐
#define WCAlignCenterHorizontally(alignedView, referencedView) (CGPointMake(referencedView.center.x, alignedView.center.y))

// 保持orgin不变，使oldFrame的CGSize和newFrame的CGSize一样
#define WCMakeCGSizeSame(oldFrame, newFrame)                   (CGRectMake(oldFrame.origin.x, oldFrame.origin.y, newFrame.size.width, newFrame.size.height))

// 两个UIView之间的space，竖直排列
#define CGRectYSpacingBy(frame, deltaY)                        CGRectMake(frame.origin.x, frame.origin.y + frame.size.height + deltaY, frame.size.width, frame.size.height)

// Check nil

//#define nilable(var) ((var) != nil ? (var) : @"(null)")

#endif /* WCMacroKit_h */
