//
//  WCMacroSafeValue.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/3/9.
//

#ifndef WCMacroSafeValue_h
#define WCMacroSafeValue_h

#pragma mark - Safe Get Value

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

/**
 Safe get instance which is kind of class type

 @param object the unsafe object
 @param classType the class type
 @return the safe object
 */
#define ValueOfClassType(object, classType) ([(object) isKindOfClass:[classType class]] ? (object) : nil)

#define ValueOfDict(object)     ValueOfClassType(object, NSDictionary)
#define ValueOfDictM(object)    ValueOfClassType(object, NSMutableDictionary)

#define ValueOfArray(object)    ValueOfClassType(object, NSArray)
#define ValueOfArrayM(object)   ValueOfClassType(object, NSMutableArray)

#define ValueOfString(object)   ValueOfClassType(object, NSString)
#define ValueOfNumber(object)   ValueOfClassType(object, NSNumber)

#pragma mark - Key Value Pair Suite

/**
 Make a pair of key value

 @param key the key object
 @param value the value object
 @return the a pair of key value
 @see https://stackoverflow.com/a/33525373
 */
#define KeyValuePair(key, value)    @[((key) ?: [NSNull null]), ((value) ?: [NSNull null])]
/**
 The type of key value pair
 */
typedef NSArray * KeyValuePairType;
/**
 Check object if a key value pair

 @param object the object
 @return YES if the object is a key value pair, or return NO if not
 */
#define KeyValuePairValidate(object)  ([(object) isKindOfClass:[NSArray class]] && [(object) count] == 2)
/**
 Get the key object of pair

 @param pair the pair object
 @return the key object
 */
#define KeyOfPair(pair)             (KeyValuePairValidate(pair) ? ([pair firstObject] == [NSNull null] ? nil : [pair firstObject]) : nil)
/**
 Get the value object of pair

 @param pair the pair object
 @return the value object
 */
#define ValueOfPair(pair)           (KeyValuePairValidate(pair) ? ([pair lastObject] == [NSNull null] ? nil : [pair lastObject]) : nil)

#pragma mark - Safe float comparison

/**
 Safe compare two float or double equality

 @param f1 the float or double
 @param f2 the float or double
 @return YES if the f1 and f2 are equal by float type. Otherwise, NO
 */
#define FLOAT_COMPARE_EQUAL(f1, f2) (fabs((float)(f1) - (float)(f2)) < FLT_EPSILON)

#pragma mark - NSDictionary

/**
 *  NSMutableDictionary calls setObject:forKey: method more safely
 */
#ifndef NSDICTIONARY_M_SAFE_SET
#define NSDICTIONARY_M_SAFE_SET(mutableDictionary, key, value) \
    do {                                                       \
        if ([mutableDictionary isKindOfClass:[NSMutableDictionary]] && key && value) { \
            [mutableDictionary setObject:value forKey:key];    \
        }                                                      \
    } while (0)

#endif /* NSDICTIONARY_M_SAFE_SET */

#ifndef NSDICTIONARY_M_SAFE_ADD_ENTRIES
#define NSDICTIONARY_M_SAFE_ADD_ENTRIES(mutableDictionary, dictionary) \
    do {                                                               \
        if ([mutableDictionary isKindOfClass:[NSMutableDictionary]] && dictionary) { \
            [mutableDictionary addEntriesFromDictionary:dictionary];   \
        }                                                              \
    } while (0)

#endif /* NSDICTIONARY_M_SAFE_ADD_ENTRIES */

#pragma mark > NSDictionary pairs

/**
 Safe to define a mutable dictionary

 @param dict the dict to define
 @param ... the key-value pairs by using NSDICTIONARY_M_PAIRS_SET macro
 @code
 
 NSDICTIONARY_M_PAIRS_DEFINE(dictM3,
    NSDICTIONARY_M_PAIRS_SET(@"key1", @"string")
    NSDICTIONARY_M_PAIRS_SET(@"key2", nil)
    NSDICTIONARY_M_PAIRS_SET(nil, @1)
 );
 // dictM3 will get @{ @"key1": @"string" }
 
 @endcode
 */
#define NSDICTIONARY_M_PAIRS_DEFINE(dict, ...) \
NSMutableDictionary *dict = \
({ \
NSMutableDictionary *dictM_internal__ = [NSMutableDictionary dictionary]; \
__VA_ARGS__; \
dictM_internal__; \
});

/**
 Return a safe mutable dictionary

 @param ... the key-value pairs by using NSDICTIONARY_M_PAIRS_SET macro
 @return the mutable dictionary
 @code
 
 NSMutableDictionary *data = NSDICTIONARY_M_PAIRS_RETURN(
     NSDICTIONARY_M_PAIRS_SET(@"a", @"A");
     NSDICTIONARY_M_PAIRS_SET(@"b", @"B");
     NSDICTIONARY_M_PAIRS_SET(@"c", nil);
     NSDICTIONARY_M_PAIRS_SET(nil, @"D");
 );
 // data will get @{ @"a": @"A", @"b": @"B" }
 
 @endcode
 */
#define NSDICTIONARY_M_PAIRS_RETURN(...) \
({ \
NSMutableDictionary *dictM_internal__ = [NSMutableDictionary dictionary]; \
__VA_ARGS__ \
dictM_internal__; \
});

/**
 Safe to set key-value

 @param key the key
 @param value the value
 @discussion This macro used in company with NSDICTIONARY_M_PAIRS_DEFINE or NSDICTIONARY_M_PAIRS_RETURN
 */
#define NSDICTIONARY_M_PAIRS_SET(key, value) \
if (key != nil) { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wnonnull\"") \
    dictM_internal__[key] = value; \
_Pragma("clang diagnostic pop") \
} \

#pragma mark > NSDictionary checking

/**
 Is a dict and not empty

 @param dict the NSDictionary object to expected
 @return Return YES if is a dict and not empty. Return NO if not.
 
 @code
 if (DICT_IF_NOT_EMPTY(dict)) {
    // do something
 }
 @endcode
 */
#define DICT_IF_NOT_EMPTY(dict)    ([(dict) isKindOfClass:[NSDictionary class]] && [(NSDictionary *)(dict) count])

#pragma mark - NSArray

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

#pragma mark > NSArray checking

/**
 Is an array and not empty

 @param arr the NSArray object to expected
 @return Return YES if is an array and not empty. Return NO if not.
 
 @code
 if (ARR_IF_NOT_EMPTY(arr)) {
    // do something
 }
 @endcode
 */
#define ARR_IF_NOT_EMPTY(arr)    ([(arr) isKindOfClass:[NSArray class]] && [(NSArray *)(arr) count])

#pragma mark - NSObject

/**
 Safe to convert an object to another propert type object without warning.
 
 @param fromObejct the object to convert
 @param toObject the declared variable
 @param toClassName the class type to match, e.g. NSMutableString
 @textblock
 
 SomeModel *model = [SomeModel new];
 NSOBJECT_TYPE_CONVERT(model.a, declared_var, NSString);
 
 @textblock
 */
#define NSOBJECT_TYPE_CONVERT(fromObject, toObject, toClassName) \
toClassName *toObject = ({ \
    toClassName *__internal_return_value; \
    if ([(fromObject) isKindOfClass:[toClassName class]]) { \
        __internal_return_value = (toClassName *)(fromObject); \
    } \
    __internal_return_value; \
});

#pragma mark - NSData

#pragma mark > Data checking

/**
 Check is a NSData and not empty

 @param data NSData to expected
 */
#define DATA_IF_NOT_EMPTY(data)    ([(data) isKindOfClass:[NSData class]] && [(NSData *)(data) length])

#pragma mark - NSURL

/**
 Safe get a NSURL from NSString

 @param url NSString to expected
 @discussion If the url is a not string or empty will get a nil
 */
#define NSURL_SAFE_NEW(url) (([(url) isKindOfClass:[NSString class]] && (url).length) ? [NSURL URLWithString:(url)] : nil)

#pragma mark - Safe Pointer

/**
 Safe set pointer's value
 
 @param ptr the pointer
 @param value the value which ptr points to
 */
#define PTR_SAFE_SET(ptr, value) \
do { \
    if (ptr) { \
        *ptr = value; \
    } \
} while (0)

#endif /* WCMacroSafeValue_h */
