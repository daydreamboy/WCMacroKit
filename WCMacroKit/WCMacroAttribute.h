//
//  WCMacroAttribute.h
//  WCMacroKit
//
//  Created by wesley_chen on 2019/9/1.
//

#ifndef WCMacroAttribute_h
#define WCMacroAttribute_h

#pragma mark - WC_RESTRICT_SUBCLASSING

/**
 WC_RESTRICT_SUBCLASSING
 
 Disable the class for subclassing
 */
#if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#define WC_RESTRICT_SUBCLASSING __attribute__((objc_subclassing_restricted))
#else // #if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#define WC_RESTRICT_SUBCLASSING
#endif // #if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)

#pragma mark - Weak

#if defined(__has_attribute) && __has_attribute(weak)

/**
 Declare an external function which maybe implemented in other static library binary
 
 @param returnType_ the return type
 @param otherSignature_ the function signature exclude return type
 
 @discussion This maco implements a weak function which body is empty, so it's safe to call the function directly.
 If any strong function has not linked, the function of the macro will do nothing.
 
 @note use (void)0 as return value, see https://stackoverflow.com/a/25172483
 */
#define WC_DECLARE_EXTERNAL_FUNC(returnType_, otherSignature_) \
extern returnType_ otherSignature_; \
returnType_ __attribute__((weak)) otherSignature_ { \
return (returnType_)0; \
}

#else  // #if defined(__has_attribute) && __has_attribute(weak)

#define WC_DECLARE_EXTERNAL_FUNC(returnType_, otherSignature_)

#endif // #if defined(__has_attribute) && __has_attribute(weak)

#pragma mark > const

#if defined(__has_attribute) && __has_attribute(weak)

/**
 Declare an external global constant which maybe implemented in other static library binary
 
 @param type_ the type
 @param global_ the variable
 
 @example
 WC_DECLARE_EXTERNAL_CONST(NSString *, global_const)
 */
#define WC_DECLARE_EXTERNAL_CONST(type_, global_) \
extern type_ global_; \
type_ __attribute__((weak)) global_ = (type_)0;

#else // #if defined(__has_attribute) && __has_attribute(weak)

#define WC_DECLARE_EXTERNAL_CONST(type_, global_)

#endif // #if defined(__has_attribute) && __has_attribute(weak)

#endif /* WCMacroAttribute_h */
