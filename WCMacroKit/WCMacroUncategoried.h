//
//  WCMacroUncategoried.h
//  WCMacroKit
//
//  Created by wesley_chen on 2018/7/25.
//

#ifndef WCMacroUncategoried_h
#define WCMacroUncategoried_h

//#pragma mark - String Path
//
//#ifndef PathForResourceInBundle
///**
// Get the path of resource file (e.g. plist)
//
// @param resource_name the resource file name with extension
// @param resource_bundle the resource bundle name without .bundle. If nil, use main bundle (.app)
// @return the path. If not exists, return nil
// */
//#define PathForResourceInBundle(resource_name, resource_bundle) \
//( \
//(resource_bundle != nil) \
//? ([[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:(resource_bundle) ofType:@"bundle"]] pathForResource:[(resource_name) stringByDeletingPathExtension] ofType:[(resource_name) pathExtension]]) \
//: ([[NSBundle mainBundle] pathForResource:[(resource_name) stringByDeletingPathExtension] ofType:[(resource_name) pathExtension]]) \
//)
//#endif
//
//#ifndef URLForResourceInBundle
///**
// Get the URL of resource file (e.g. plist)
//
// @param resource_name the resource file name with extension
// @param resource_bundle the resource bundle name without .bundle. If nil, use main bundle (.app)
// @return the path. If not exists, return nil
// */
//#define URLForResourceInBundle(resource_name, resource_bundle) \
//( \
//(resource_bundle != nil) \
//? ([[NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:(resource_bundle) withExtension:@"bundle"]] URLForResource:[(resource_name) stringByDeletingPathExtension] withExtension:[(resource_name) pathExtension]]) \
//: ([[NSBundle mainBundle] URLForResource:[(resource_name) stringByDeletingPathExtension] withExtension:[(resource_name) pathExtension]]) \
//)
//#endif

#pragma mark - NSBundle

/**
 Get a NSBundle of main resource (.app) or resource bundle (.bundle)

 @param resource_bundle the resource bundle name without .bundle. If nil, use main bundle (.app)
 @return an object of NSBundle. Return nil if not found.
 */
#define ResourceBundle(resource_bundle) \
( \
(resource_bundle != nil) \
? ([NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:(resource_bundle) ofType:@"bundle"]]) \
: [NSBundle mainBundle] \
)

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

#pragma mark > CGSize

/**
 Get new size with width and height scaled by the same ratio

 @param size the original size
 @param scale the scale ratio
 @return the new size
 */
#define CGSizeScaled(size, scale) (CGSizeMake((size).width * (scale), (size).height * (scale)))

// Debug
#pragma mark - Debug

// DEBUG_UI
#ifndef DEBUG_UI
#define DEBUG_UI  1
#endif

// Short Code (Others)
#pragma mark - Short Code (Others)

// NSPredicate

/**
 Create a NSPredicate objec with regular expression

 @param expression the regular expression
 @return the NSPredicate object
 
 @code
 NSString *object = ....
 if ([NSPREDICATE(@"0|[1-9]\\d*") evaluateWithObject:object]) {
    // match
 }
 else {
    // not match
 }
 @endcode
 */
#define NSPREDICATE(expression)   ([NSPredicate predicateWithFormat:@"SELF MATCHES %@", expression])

// NSIndexPath
#define NSINDEXPATH(section, row) ([NSIndexPath indexPathForRow:row inSection:section])

/**
 Judge the equality of two NSIndexPath

 @param indexPath1 the indexPath1, expect it not nil
 @param indexPath2 the indexPath2, expect it not nil
 @return YES if indexPath1 is same as indexPath2
 @warning If indexPath1 or indexPath2 is nil, always return NO
 */
#define NSIndexPathEqualToIndexPath(indexPath1, indexPath2) \
((indexPath1 && indexPath2) && (indexPath1.section == indexPath2.section) && (indexPath1.row == indexPath2.row))

/**
 macro for [UIImage imageNamed:@"xxx"]

 @param imageName the name of image
 @param resource_bundle the resource bundle (with .bundle) containes image. @"" is for main bundle
 @return the UIImage object
 */
#define UIImageInResourceBundle(imageName, resource_bundle)  ([UIImage imageNamed:[(resource_bundle) stringByAppendingPathComponent:(imageName)]])

// Define @property (nonatomic, assign/strong, class) type getterName;
#define CLASS_PROPERTY_DEFINITION(getterName, setterName, type) \
@dynamic getterName; \
static type __static_##getterName; \
+ (void)setterName:(type)object { \
    __static_##getterName = object; \
} \
+ (type)getterName { \
    return __static_##getterName; \
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

#pragma mark > Show Alert
// show alert
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

/**
 Show a simple alert with tips

 @param title the title string
 @param msg the message string
 @param cancel the title of Cancel button
 @param dismissCompletion the callback when Cancel button tapped
 
 @code
 
 SHOW_ALERT(@"下载json文件出错", ([NSString stringWithFormat:@"%@", error]), @"确定", { self.ignoreScanCallback = NO; });
 SHOW_ALERT(@"扫码出错", ([NSString stringWithFormat:@"请检查格式，%@", URL]), @"确定", self.ignoreScanCallback = NO;);
 SHOW_ALERT(@"扫码出错", ([NSString stringWithFormat:@"请检查格式，%@", URL]), @"确定", nil);
 
 @endcode
 
 @discussion This macro not always works (e.g. navController present vc A, and A show alert will not show)
 and only for debugging. Use WCAlertTool instead.
 */
#define SHOW_ALERT(title, msg, cancel, dismissCompletion) \
\
do { \
    if ([UIAlertController class]) { \
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:(title) message:(msg) preferredStyle:UIAlertControllerStyleAlert]; \
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:(cancel) style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) { \
            dismissCompletion; \
        }]; \
        [alert addAction:cancelAction]; \
        [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alert animated:YES completion:nil]; \
    } \
} while (0)

#else // __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

#define SHOW_ALERT(title, msg, cancel, dismissCompletion) \
\
do { \
    if ([UIAlertController class]) { \
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:(title) message:(msg) preferredStyle:UIAlertControllerStyleAlert]; \
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:(cancel) style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) { \
            dismissCompletion; \
        }]; \
        [alert addAction:cancelAction]; \
        [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:alert animated:YES completion:nil]; \
    } \
    else { \
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:(title) message:(msg) delegate:nil cancelButtonTitle:(cancel) otherButtonTitles:nil]; \
        [alert show]; \
    } \
} while (0)

#endif // __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000


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


#pragma mark - Toll-free Bridge

#if __has_feature(objc_arc)

#define toCF (__bridge CFTypeRef)
#define fromCF (__bridge id)

#else

#define toCF (CFTypeRef)
#define fromCF (id)

#endif

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


#endif /* WCMacroUncategoried_h */
