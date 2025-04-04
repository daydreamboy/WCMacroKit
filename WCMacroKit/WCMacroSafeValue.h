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

#pragma mark - Check Type

/**
 Safe get instance which is kind of class type

 @param object the unsafe object
 @param classType the class type
 @return the safe object
 */
#define ValueOfClassType(object_, classType_, default_) (classType_ *)([(object_) isKindOfClass:[classType_ class]] ? (object_) : (default_))

#pragma mark > Check Type (Return nil)

#define ValueOfDict(object_)     ValueOfClassType(object_, NSDictionary, nil)
#define ValueOfDictM(object_)    ValueOfClassType(object_, NSMutableDictionary, nil)

#define ValueOfArray(object_)    ValueOfClassType(object_, NSArray, nil)
#define ValueOfArrayM(object_)   ValueOfClassType(object_, NSMutableArray, nil)

#define ValueOfString(object_)   ValueOfClassType(object_, NSString, nil)
#define ValueOfNumber(object_)   ValueOfClassType(object_, NSNumber, nil)

#pragma mark > Check Type (Return default)

#define ValueOfDict2(object_, default_)     ValueOfClassType(object_, NSDictionary, default_)
#define ValueOfDictM2(object_, default_)    ValueOfClassType(object_, NSMutableDictionary, default_)

#define ValueOfArray2(object_, default_)    ValueOfClassType(object_, NSArray, default_)
#define ValueOfArrayM2(object_, default_)   ValueOfClassType(object_, NSMutableArray, default_)

#define ValueOfString2(object_, default_)   ValueOfClassType(object_, NSString, default_)
#define ValueOfNumber2(object_, default_)   ValueOfClassType(object_, NSNumber, default_)

#pragma mark - JSON Value

#pragma mark > Safe Get JSON Value

/**
 Get value from JSON value

 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @param valueType the value type expected
 @param defaultValue the default value
 @return the value
 @discussion This method gets value from NSString or NSNumber unstrictly. Otherwise, get the defaultValue
 */
#define valueOfJSONValue(JSONValue, valueType, defaultValue) (([(JSONValue) isKindOfClass:[NSString class]] || [(JSONValue) isKindOfClass:[NSNumber class]]) ? [(NSString *)(JSONValue) valueType##Value] : (defaultValue))

/**
 Get string value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @param defaultValue the default value
 @return the value
 
 @discussion This method gets value from NSString or NSNumber unstrictly. Otherwise, get the defaultValue
 */
#define stringValueOfJSONValueWithDefault(JSONValue, defaultValue)   ([(JSONValue) isKindOfClass:[NSString class]] ? (JSONValue) : ([(JSONValue) isKindOfClass:[NSNumber class]]) ? [(NSNumber *)(JSONValue) stringValue] : (defaultValue))

/**
 Get double value from JSON value (NSString/NSNumber)

 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return 0.0
 */
#define doubleValueOfJSONValue(JSONValue)   valueOfJSONValue(JSONValue, double, 0.0)
#define doubleValueOfJSONValueWithDefault(JSONValue, defaultValue)  valueOfJSONValue(JSONValue, double, defaultValue)

/**
 Get float value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return 0.0f
 */
#define floatValueOfJSONValue(JSONValue)    valueOfJSONValue(JSONValue, float, 0.0f)
#define floatValueOfJSONValueWithDefault(JSONValue, defaultValue)    valueOfJSONValue(JSONValue, float, defaultValue)

/**
 Get int value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return 0
 */
#define intValueOfJSONValue(JSONValue)      valueOfJSONValue(JSONValue, int, 0)
#define intValueOfJSONValueWithDefault(JSONValue, defaultValue)      valueOfJSONValue(JSONValue, int, defaultValue)

/**
 Get NSInteger value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return 0
 */
#define integerValueOfJSONValue(JSONValue)  valueOfJSONValue(JSONValue, integer, 0)
#define integerValueOfJSONValueWithDefault(JSONValue, defaultValue)  valueOfJSONValue(JSONValue, integer, defaultValue)

/**
 Get long long value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return 0
 */
#define longLongValueOfJSONValue(JSONValue) valueOfJSONValue(JSONValue, longLong, 0LL)
#define longLongValueOfJSONValueWithDefault(JSONValue, defaultValue) valueOfJSONValue(JSONValue, longLong, defaultValue)

/**
 Get BOOL value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return NO
 */
#define boolValueOfJSONValue(JSONValue)     valueOfJSONValue(JSONValue, bool, NO)
#define boolValueOfJSONValueWithDefault(JSONValue, defaultValue)     valueOfJSONValue(JSONValue, bool, defaultValue)

/**
 Get NSString value from JSON value (NSString/NSNumber)
 
 @param JSONValue the JSON value (NSString, NSNumber, NSArray, NSDictionary, or NSNull) or others
 @return the value. Unexpected JSONValue will return nil
 */
#define stringValueOfJSONValue(JSONValue)   stringValueOfJSONValueWithDefault(JSONValue, nil)

/**
 Get JSON object from JSON string

 @param ... the JSON string
 @return the JSON object. Return nil if the JSON string is invalid.
 */
#define JSONObjectFromJSONString(...) \
({ \
    id JSONObject__; \
    @try { \
        JSONObject__ = [NSJSONSerialization JSONObjectWithData:[@#__VA_ARGS__ dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingAllowFragments error:nil]; \
    } \
    @catch (NSException *exception) { \
    } \
    JSONObject__; \
});

/**
 Get mutable JSON object from JSON string
 
 @param ... the JSON string
 @return the JSON object. Return nil if the JSON string is invalid.
 @discussion Return the JSON object with both mutable containers and leaves
 */
#define JSONMutableObjectFromJSONString(...) \
({ \
    id JSONObject__; \
    @try { \
        JSONObject__ = [NSJSONSerialization JSONObjectWithData:[@#__VA_ARGS__ dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingAllowFragments | NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves error:nil]; \
    } \
    @catch (NSException *exception) { \
    } \
    JSONObject__; \
});

#pragma mark - NSValue

/**
 Get primitive value from NSValue
 
 @param nsValue_ the NSValue object
 @param primitiveType_ the primitive type, e.g. int, double, ...
 
 @return the primitive value
 */
#define primitiveValueFromNSValue(nsValue_, primitiveType_) \
({ \
primitiveType_ outValue__; \
if (([[[UIDevice currentDevice] systemVersion] compare:@"11.0" options:NSNumericSearch] != NSOrderedAscending)) { \
    [nsValue_ getValue:&outValue__]; \
} \
else { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wunguarded-availability\"") \
    [nsValue_ getValue:&outValue__ size:sizeof(primitiveType_)]; \
_Pragma("clang diagnostic pop") \
} \
outValue__; \
});

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
 NSDictionary safe get value

 @param dictionary the NSDictionary object
 @param key the key
 @param valueClassType the value class to check. If nil or @"", not check the value class
 @return the value if (1) dictionary is NSDictionary, (2) key not nil, (3) dictionary[key] exists, (4) value matches valueClassType when valueClassType not nil.
 Otherwise, return nil
 @code
 
 dict = @{
    @"key": @"date"
 };
 value = DICT_SAFE_GET(dict, @"key", NSString);
 value = DICT_SAFE_GET(dict, @"key", nil);
 value = DICT_SAFE_GET(dict, @"key", @"");
 
 @endcode
 */
#ifndef DICT_SAFE_GET
#define DICT_SAFE_GET(dictionary, key, valueClassType) \
({ \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
    NSClassFromString(@#valueClassType) ? \
    (([(dictionary) isKindOfClass:[NSDictionary class]] && (key) && dictionary[(key)] && [dictionary[(key)] isKindOfClass:NSClassFromString(@#valueClassType)]) ? dictionary[(key)] : nil) : \
    (([(dictionary) isKindOfClass:[NSDictionary class]] && (key) && dictionary[(key)]) ? dictionary[(key)] : nil); \
    _Pragma("clang diagnostic pop") \
})

#endif /* DICT_SAFE_GET */

/**
 *  NSMutableDictionary calls setObject:forKey: method more safely
 */
#ifndef DICT_M_SAFE_SET
#define DICT_M_SAFE_SET(mutableDictionary, key, value) \
    do {                                                       \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
        if ([mutableDictionary isKindOfClass:[NSMutableDictionary class]] && key && value) { \
            [mutableDictionary setObject:value forKey:key];    \
        }                                                      \
_Pragma("clang diagnostic pop") \
    } while (0)

#endif /* DICT_M_SAFE_SET */

#ifndef DICT_M_SAFE_ADD_ENTRIES
#define DICT_M_SAFE_ADD_ENTRIES(mutableDictionary, dictionary) \
    do {                                                               \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
        if ([mutableDictionary isKindOfClass:[NSMutableDictionary class]] && [dictionary isKindOfClass:[NSDictionary class]]) { \
            [mutableDictionary addEntriesFromDictionary:dictionary];   \
        }                                                              \
_Pragma("clang diagnostic pop") \
    } while (0)

#endif /* DICT_M_SAFE_ADD_ENTRIES */

/**
 Safe to wrap the literal dictionary

 @param ... the literal dictionary
 @return the literal dictionary if no nil keys or values. Return nil if key or value is nil
 
 @code
 
 dict = DICT_SAFE_WRAP(@{
     keyMaybeNil: @"value",
     @"key": valueMaybeNil
 });
 
 @endcode
 */
#ifndef DICT_SAFE_WRAP
#define DICT_SAFE_WRAP(...) ({ \
    NSDictionary *internalDict_; \
    @try { \
        internalDict_ = __VA_ARGS__; \
    } \
    @catch (NSException *e) {} \
    internalDict_; \
    });

#endif /* DICT_SAFE_WRAP */

#pragma mark > NSDictionary pairs

/**
 Safe to define a mutable dictionary

 @param dict the dict to define
 @param ... the key-value pairs by using DICT_M_PAIRS_SET macro
 @code
 
 DICT_M_PAIRS_DEFINE(dictM3,
    DICT_M_PAIRS_SET(@"key1", @"string")
    DICT_M_PAIRS_SET(@"key2", nil)
    DICT_M_PAIRS_SET(nil, @1)
 );
 // dictM3 will get @{ @"key1": @"string" }
 
 @endcode
 */
#define DICT_M_PAIRS_DEFINE(dict, ...) \
NSMutableDictionary *dict = \
({ \
NSMutableDictionary *dictM_internal__ = [NSMutableDictionary dictionary]; \
__VA_ARGS__; \
dictM_internal__; \
});

/**
 Return a safe mutable dictionary

 @param ... the key-value pairs by using DICT_M_PAIRS_SET macro
 @return the mutable dictionary
 @code
 
 NSMutableDictionary *data = DICT_M_PAIRS_RETURN(
     DICT_M_PAIRS_SET(@"a", @"A");
     DICT_M_PAIRS_SET(@"b", @"B");
     DICT_M_PAIRS_SET(@"c", nil);
     DICT_M_PAIRS_SET(nil, @"D");
 );
 // data will get @{ @"a": @"A", @"b": @"B" }
 
 @endcode
 */
#define DICT_M_PAIRS_RETURN(...) \
({ \
NSMutableDictionary *dictM_internal__ = [NSMutableDictionary dictionary]; \
__VA_ARGS__ \
dictM_internal__; \
});

/**
 Safe to set key-value

 @param key the key
 @param value the value
 @discussion This macro used in company with DICT_M_PAIRS_DEFINE or DICT_M_PAIRS_RETURN
 */
#define DICT_M_PAIRS_SET(key, value) \
if (key != nil) { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wnonnull\"") \
    dictM_internal__[key] = value; \
_Pragma("clang diagnostic pop") \
}

#pragma mark > NSDictionary pairs (new style)

#define DICT_M_PAIRS_1(dict_, pair1_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:1]; \
dict_ pair1_;

#define DICT_M_PAIRS_2(dict_, pair1_, pair2_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:2]; \
dict_ pair1_; \
dict_ pair2_;

#define DICT_M_PAIRS_3(dict_, pair1_, pair2_, pair3_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:3]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_;

#define DICT_M_PAIRS_4(dict_, pair1_, pair2_, pair3_, pair4_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:4]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_;

#define DICT_M_PAIRS_5(dict_, pair1_, pair2_, pair3_, pair4_, pair5_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:5]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_;

#define DICT_M_PAIRS_6(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:6]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_;

#define DICT_M_PAIRS_7(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:7]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_;

#define DICT_M_PAIRS_8(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:8]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_;

#define DICT_M_PAIRS_9(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:9]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_;

#define DICT_M_PAIRS_10(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:10]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_;

#define DICT_M_PAIRS_11(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_, pair11_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:11]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_; \
dict_ pair11_;

#define DICT_M_PAIRS_12(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_, pair11_, pair12_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:12]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_; \
dict_ pair11_; \
dict_ pair12_;

#define DICT_M_PAIRS_13(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_, pair11_, pair12_, pair13_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:13]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_; \
dict_ pair11_; \
dict_ pair12_; \
dict_ pair13_;

#define DICT_M_PAIRS_14(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_, pair11_, pair12_, pair13_, pair14_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:14]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_; \
dict_ pair11_; \
dict_ pair12_; \
dict_ pair13_; \
dict_ pair14_;

#define DICT_M_PAIRS_15(dict_, pair1_, pair2_, pair3_, pair4_, pair5_, pair6_, pair7_, pair8_, pair9_, pair10_, pair11_, pair12_, pair13_, pair14_, pair15_) \
NSMutableDictionary *dict_ = [NSMutableDictionary dictionaryWithCapacity:15]; \
dict_ pair1_; \
dict_ pair2_; \
dict_ pair3_; \
dict_ pair4_; \
dict_ pair5_; \
dict_ pair6_; \
dict_ pair7_; \
dict_ pair8_; \
dict_ pair9_; \
dict_ pair10_; \
dict_ pair11_; \
dict_ pair12_; \
dict_ pair13_; \
dict_ pair14_; \
dict_ pair15_;

#define DICT_M_PAIRS_SHIFT(x,y,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,FUNC, ...) FUNC

/**
 Shorthand for creating a mutable dictionary
 
 @param dict_ the variable name
 @param ... the key/value pairs
 
 @example
 DICT_M_PAIRS(dict2,
  [@"1"] = @1,
  [@"2"] = @2
 )
 // use dict2 afterward here...
 */
#define DICT_M_PAIRS(dict_, ...) \
DICT_M_PAIRS_SHIFT(,dict_,##__VA_ARGS__, \
DICT_M_PAIRS_15(dict_, __VA_ARGS__), \
DICT_M_PAIRS_14(dict_, __VA_ARGS__), \
DICT_M_PAIRS_13(dict_, __VA_ARGS__), \
DICT_M_PAIRS_12(dict_, __VA_ARGS__), \
DICT_M_PAIRS_11(dict_, __VA_ARGS__), \
DICT_M_PAIRS_10(dict_, __VA_ARGS__), \
DICT_M_PAIRS_9(dict_, __VA_ARGS__), \
DICT_M_PAIRS_8(dict_, __VA_ARGS__), \
DICT_M_PAIRS_7(dict_, __VA_ARGS__), \
DICT_M_PAIRS_6(dict_, __VA_ARGS__), \
DICT_M_PAIRS_5(dict_, __VA_ARGS__), \
DICT_M_PAIRS_4(dict_, __VA_ARGS__), \
DICT_M_PAIRS_3(dict_, __VA_ARGS__), \
DICT_M_PAIRS_2(dict_, __VA_ARGS__), \
DICT_M_PAIRS_1(dict_, __VA_ARGS__), \
)

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

/**
 Is a dict and empty

 @param dict the NSDictionary object to expected
 @return Return YES if is a dict and empty. Return NO if not.
 
 @code
 if (DICT_IF_EMPTY(dict)) {
    // do something
 }
 @endcode
 */
#define DICT_IF_EMPTY(dict)    ([(dict) isKindOfClass:[NSDictionary class]] && [(NSDictionary *)(dict) count] == 0)

#pragma mark - NSArray

/*!
 *  Replace elements of NSMutableArray
 *
 *  @param mutableArray the mutable array
 *  @param index        the index
 *  @param value        the value
 */
#ifndef ARR_M_SAFE_SET
#define ARR_M_SAFE_SET(mutableArray, index, value)                    \
    do {                                                                  \
        if ([mutableArray isKindOfClass:[NSMutableArray class]] && 0 <= index && index < [(NSMutableArray *)mutableArray count]) { \
            ((NSMutableArray *)mutableArray)[index] = value;                                  \
        }                                                                 \
    } while (0)
#endif /* ARR_M_SAFE_SET */

// Note: in macro, use _Pragma("clang diagnostic push") instead of #pragma GCC diagnostic push
#ifndef ARR_M_SAFE_ADD
#define ARR_M_SAFE_ADD(mutableArray, value) \
    do { \
            id __value__ = value; \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
            if ([mutableArray isKindOfClass:[NSMutableArray class]] && __value__) { \
                [(NSMutableArray *)mutableArray addObject:__value__]; \
            } \
_Pragma("clang diagnostic pop") \
    } while (0)
#endif /* ARR_M_SAFE_ADD */

#ifndef ARR_M_SAFE_ADD_ENTRIES
#define ARR_M_SAFE_ADD_ENTRIES(mutableArray_, array_) \
    do { \
            id __value__ = array_; \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
            if ([mutableArray_ isKindOfClass:[NSMutableArray class]] && __value__) { \
                [(NSMutableArray *)mutableArray_ addObjectsFromArray:__value__]; \
            } \
_Pragma("clang diagnostic pop") \
    } while (0)
#endif /* ARR_M_SAFE_ADD_ENTRIES */

#ifndef ARR_M_SAFE_REMOVE
#define ARR_M_SAFE_REMOVE(mutableArray, index) \
    do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wobjc-literal-conversion\"") \
            if ([mutableArray isKindOfClass:[NSMutableArray class]] && 0 <= index && index < [(NSMutableArray *)mutableArray count]) { \
                [(NSMutableArray *)mutableArray removeObjectAtIndex:index]; \
            } \
_Pragma("clang diagnostic pop") \
    } while (0)
#endif /* ARR_M_SAFE_REMOVE */

/*!
 *  Get value at index of NSArray
 *
 *  @param array the array
 *  @param index the index
 *
 *  @return the value at index. If nil, when index out of bound
 */
#ifndef ARR_SAFE_GET
#define ARR_SAFE_GET(array, index) \
    ({ \
        id __value = nil; \
        if ([array isKindOfClass:[NSArray class]] && 0 <= index && index < [(NSArray *)array count]) { \
            __value = [(NSArray *)array objectAtIndex:index]; \
        } \
        __value; \
    })
#endif /* ARR_SAFE_GET */


#ifndef ARR_SAFE_WRAP
#define ARR_SAFE_WRAP(...) ({ \
    NSArray *internalArr_; \
    @try { \
        internalArr_ = __VA_ARGS__; \
    } \
    @catch (NSException *e) {} \
    internalArr_; \
    });
#endif /* ARR_SAFE_WRAP */

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

/**
 Is an array and empty

 @param arr the NSArray object to expected
 @return Return YES if is an array and empty. Return NO if not.
 
 @code
 if (ARR_IF_EMPTY(arr)) {
    // do something
 }
 @endcode
 */
#define ARR_IF_EMPTY(arr)    ([(arr) isKindOfClass:[NSArray class]] && [(NSArray *)(arr) count] == 0)

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
 Safe get a URL from NSString

 @param url NSString to expected
 @return the NSURL instance. If the url is a not string or empty will get a nil
 @discussion This method will trim the url at head and at trail.
 */
#define NSURL_SAFE_NEW(url) (([(url) isKindOfClass:[NSString class]] && (url).length) ? [NSURL URLWithString:[(url) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]] : nil)

/**
 Safe get a file path URL from NSString

 @param url NSString to expected
 @return If the url is a not string or empty will get a nil
 */
#define NSURL_PATH_SAFE_NEW(path) (([(path) isKindOfClass:[NSString class]] && (path).length) ? [NSURL fileURLWithPath:(path)] : nil)

#pragma mark - File Path

/**
 Create a temp file path located in NSTemporaryDirectory()

 @param ext the file extension, e.g. @"txt". If nil, for without file extension.
 @return the file path
 @discussion the file name format is `tmp_<unix timestamp in ms>_<random number>`.
 
 @code
 
 NSString *filePath = TEMP_FILE_PATH_NEW(@"txt");
 BOOL success = [JEPGData writeToFile:filePath atomically:YES];
 
 @endcode
 */
#define TEMP_FILE_PATH_NEW(ext)  ([[NSTemporaryDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"tmp_%ld_%u", (long)([[NSDate date] timeIntervalSince1970] * 1000), arc4random()]] stringByAppendingPathExtension:[(id)(ext) isKindOfClass:[NSString class]] ? (ext) : @""])

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

#pragma mark - Safe Comparison

#define DOUBLE_SAFE_MAX(a, b) \
({ \
double __returnValue; \
double __v1 = (a); \
double __v2 = (b); \
if (__v1 >= __v2) { \
    __returnValue = __v1; \
} \
else { \
    __returnValue = __v2; \
} \
__returnValue; \
});

#pragma mark - Safe Type Cast

/**
 Safe convert type for an object
 
 @param object_ the object
 @param class_ the Class type
 
 @return If can't convert type, return nil
 */
#define TYPE_CAST(object_, class_) ({ \
    id __object__ = (object_); \
    [__object__ isKindOfClass:[class_ class]] ? (class_ *)__object__ : nil; \
})

#pragma mark - Safe Execute Expression (with Return Value)

/**
 Wrap expression with try-catch
 
 @param ... the expression
 @return The id type object. If exception happened, return nil
 
 @example
 `SAFE_EXC_EXP([[UUIDs valueForKeyPath:@"self.UUIDString"] componentsJoinedByString:@","]);`
 */
#ifndef SAFE_EXC_EXP
#define SAFE_EXC_EXP(...) ({ \
    id internalRetVal_ = nil; \
    @try { \
        internalRetVal_ = __VA_ARGS__; \
    } \
    @catch (NSException *e) {} \
    internalRetVal_; \
});
#endif /* SAFE_EXC_EXP */

#ifndef SAFE_EXC_EXP_WITH_EXCP
#define SAFE_EXC_EXP_WITH_EXCP(outException_, ...) ({ \
    id internalRetVal_ = nil; \
    @try { \
        internalRetVal_ = __VA_ARGS__; \
    } \
    @catch (NSException *__e__) { \
        outException_ = __e__; \
    } \
    internalRetVal_; \
});
#endif /* SAFE_EXC_EXP */

#pragma mark - Safe Execute Code (without Return Value)


#ifndef SAFE_EXC_CODE
#define SAFE_EXC_CODE(...) \
    @try { \
        __VA_ARGS__; \
    } \
    @catch (NSException *e) {}
#endif /* SAFE_EXC_CODE */


#ifndef SAFE_EXC_CODE_WITH_EXCP
#define SAFE_EXC_CODE_WITH_EXCP(outException_, ...) \
    @try { \
        __VA_ARGS__; \
    } \
    @catch (NSException *__e__) { \
        outException_ = __e__; \
    }
#endif /* SAFE_EXC_CODE_WITH_EXCP */


#endif /* WCMacroSafeValue_h */
