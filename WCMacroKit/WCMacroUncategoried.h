//
//  WCMacroUncategoried.h
//  WCMacroKit
//
//  Created by wesley_chen on 2018/7/25.
//

#ifndef WCMacroUncategoried_h
#define WCMacroUncategoried_h

// String
#pragma mark - String

#pragma mark > String conversion

// BOOL to string
#define STR_OF_BOOL(yesOrNo)     ((yesOrNo) ? @"YES" : @"NO")
// property name to string
#define STR_OF_PROP(property)    (NSStringFromSelector(@selector(property)))

/**
 literal JSON c string to NSString

 @param ... the literal string
 @return the NSString
 @see https://stackoverflow.com/a/14293615
 @warning the `\n` will replaced by ` `
 */
#define STR_OF_JSON(...) @#__VA_ARGS__

#pragma mark > String modidication

// Catenate two strings
#define STR_CATENATE(str1, str2) ([NSString stringWithFormat:@"%@%@", str1, str2])
// Short formated string
#define STR_FORMAT(format, ...) ([NSString stringWithFormat:format, __VA_ARGS__])
// Trim a string
#define STR_TRIM(str) ([(str) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]])

#pragma mark > String checking
// Is a string and not empty
#define STR_IF_NOT_EMPTY(str)    ([(str) isKindOfClass:[NSString class]] && [(NSString *)(str) length])

// Is a string and empty
#define STR_IF_EMPTY(str)        ([(str) isKindOfClass:[NSString class]] && [(NSString *)(str) length] == 0)

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
                                               options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)  \
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
                                           options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)  \
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

//
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000

/**
 Alert some tips

 @param title the title string
 @param msg the message string
 @param cancel the title of Cancel button
 @param dismissCompletion the callback when Cancel button tapped
 
 @code
 ALERT_TIP(@"下载json文件出错", ([NSString stringWithFormat:@"%@", error]), @"确定", { self.ignoreScanCallback = NO; });
 ALERT_TIP(@"扫码出错", ([NSString stringWithFormat:@"请检查格式，%@", URL]), @"确定", self.ignoreScanCallback = NO;);
 ALERT_TIP(@"扫码出错", ([NSString stringWithFormat:@"请检查格式，%@", URL]), @"确定", nil);
 */
#define ALERT_TIP(title, msg, cancel, dismissCompletion) \
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

#define ALERT_TIP(title, msg, cancel, dismissCompletion) \
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

#pragma mark > NSError

#define WCSafeSetErrorPtr(errorPtr, error) \
do { \
    if (errorPtr) { \
        *errorPtr = error; \
    } \
} while (0)

#pragma mark > Safe Get Value

/**
 Safe get integer

 @param number the NSNumber
 @return the NSInteger. Return NSNotFound if the number is not NSNumber
 */
#define numberInteger(number) \
({ \
NSInteger integer = NSNotFound; \
if ([(number) isKindOfClass:[NSNumber class]]) { \
    integer = [(number) integerValue]; \
} \
integer; \
})

#pragma mark > Weak-Strong Dance

/**
 Weakify the object variable

 @param object the original variable
 @discussion Use weakify/strongify as pair
 @see https://www.jianshu.com/p/9e18f28bf28d
 @see https://github.com/ReactiveCocoa/ReactiveObjC/blob/master/ReactiveObjC/extobjc/EXTScope.h#L83
 @code
 
 id foo = [[NSObject alloc] init];
 id bar = [[NSObject alloc] init];
 
 weakify(foo);
 weakify(bar);
 
 // this block will not keep 'foo' or 'bar' alive
 BOOL (^matchesFooOrBar)(id) = ^ BOOL (id obj){
    // but now, upon entry, 'foo' and 'bar' will stay alive until the block has
    // finished executing
    strongify(foo);
    strongifyWithReturn(bar, return NO);
 
    return [foo isEqual:obj] || [bar isEqual:obj];
 };
 
 @endcode
 */
#define weakify(object) \
__weak __typeof__(object) object##_weak_ = object;

/**
 Strongify the weak object variable which is created by weakify(object)

 @param object the original variable
 @discussion Use weakify/strongify as pair
 @see https://www.jianshu.com/p/9e18f28bf28d
 @note See #weakify for an example of usage.
 */
#define strongify(object) \
__typeof__(object) object = object##_weak_;

/**
 Strongify the weak object variable which is created by weakify(object).
 And optional add a return clause

 @param object the original variable
 @param ... the return clause
 @discussion strongifyWithReturn works as strongify, except for allowing a return clause
 @note See #weakify for an example of usage.
 */
#define strongifyWithReturn(object, ...) \
__typeof__(object) object = object##_weak_; \
if (!object) { \
    __VA_ARGS__; \
}

#pragma mark - Safe float comparison

/**
 Safe compare two float or double equality

 @param f1 the float or double
 @param f2 the float or double
 @return YES if the f1 and f2 are equal by float type. Otherwise, NO
 */
#define FLOAT_COMPARE_EQUAL(f1, f2) (fabs((float)(f1) - (float)(f2)) < FLT_EPSILON)

#pragma mark - Check Device Model

// http://stackoverflow.com/a/13156390/4794665
#define IS_IPAD             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA           ([[UIScreen mainScreen] scale] >= 2.0)
#define SCREEN_WIDTH        ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT       ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH   (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH   (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

// @see https://www.paintcodeapp.com/news/ultimate-guide-to-iphone-resolutions

// iPhone 3GS or iPhone 3G or iPhone 2G (@1x)
#define IS_IPHONE_3_OR_LESS   (IS_IPHONE && SCREEN_MAX_LENGTH == 480.0 && [UIScreen mainScreen].scale == 1.0)

// iPhone 4 or iPhone 4s (@2x)
#define IS_IPHONE_4_OR_4S   (IS_IPHONE && SCREEN_MAX_LENGTH == 480.0 && [UIScreen mainScreen].scale == 2.0)

// iPhone 4 or iPhone 4s (@2x)
// or
// iPhone 2G or iPhone 3G or iPhone 3GS (@1x)
#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)

// iPhone 5 or iPhone 5s or iPhone 5c or iPhone SE (@2x)
#define IS_IPHONE_5_OR_5S_OR_5C_OR_SE   (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)

// iPhone 6 or iPhone 6s or iPhone 7 or iPhone 8 (@2x)
#define IS_IPHONE_6_OR_6S_OR_7_OR_8 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)

// iPhone 6P or iPhone 6SP or iPhone 7P or iPhone 8P (@3x)
#define IS_IPHONE_6P_OR_6SP_OR_7P_OR_8P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

// iPhone X or iPhone Xs (@3x)
// @see https://stackoverflow.com/questions/46196964/detect-iphone-x-with-a-macro
#define IS_IPHONE_X_OR_XS   (IS_IPHONE && SCREEN_MAX_LENGTH == 812.0)

// iPhone Xr (@2x)
#define IS_IPHONE_XR    (IS_IPHONE && SCREEN_MAX_LENGTH == 896.0 && [UIScreen mainScreen].scale == 2.0)

// iPhone Xs Max (@3x)
#define IS_IPHONE_XS_MAX    (IS_IPHONE && SCREEN_MAX_LENGTH == 896.0 && [UIScreen mainScreen].scale == 3.0)

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

#define NSDICTIONARY_M_PAIRS_BEGIN(dict) \
NSMutableDictionary *dict = \
({ \
NSMutableDictionary *dictM_internal = [NSMutableDictionary dictionary];

#define NSDICTIONARY_M_PAIRS_END \
dictM_internal; \
});

#define NSDICTIONARY_M_PAIRS_SET(key, value) \
dictM_internal[key] = value;

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

// Note: in macro, use _Pragma("clang diagnostic push") instead of #pragma GCC diagnostic push
#ifndef NSARRAY_M_SAFE_ADD
#define NSARRAY_M_SAFE_ADD(mutableArray, value) \
    do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
            if ([mutableArray isKindOfClass:[NSMutableArray class]] && value) { \
                [mutableArray addObject:value]; \
            } \
_Pragma("clang diagnostic pop") \
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
        id __value = nil;                                   \
        if (array && 0 <= index && index < [array count]) { \
            __value = [array objectAtIndex:index];          \
        }                                                   \
        __value;                                            \
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

#pragma mark NSURL

/**
 Safe to wrap +[NSURL fileURLWithPath:]

 @param path the path, and maybe nil
 @return the NSURL
 */
#define NSURL_fileURLWithPath(path) ((path) ? [NSURL fileURLWithPath:(path) : nil)

#pragma mark NSObject
/**
 Safe to convert an object to another propert type object without warning.
 
 @param toObject the declared variable
 @param fromObejct the object to convert
 @param toClassName the class type to match, e.g. NSMutableString
 */
#define NSOBJECT_TYPE_CONVERT(toObject, fromObject, toClassName) \
toClassName *toObject = ({ \
    toClassName *__internal_return_value; \
    if ([(fromObject) isKindOfClass:[toClassName class]]) { \
        __internal_return_value = (toClassName *)(fromObject); \
    } \
    __internal_return_value; \
});

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
