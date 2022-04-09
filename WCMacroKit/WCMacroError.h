//
//  WCMacroError.h
//  WCMacroKit
//
//  Created by wesley_chen on 2022/4/8.
//

#ifndef WCMacroError_h
#define WCMacroError_h

#ifndef WCErrorDomainMake
#define WCErrorDomainMake ([[NSString alloc] initWithFormat:@"%@ErrorDomain", NSStringFromClass([self class])])
#endif

#ifndef WCErrorMake
#define WCErrorMake(code_, reason_) ([NSError errorWithDomain:[[NSString alloc] initWithFormat:@"%@ErrorDomain", NSStringFromClass([self class])] code:(code_) userInfo:@{ NSLocalizedFailureReasonErrorKey: ([(NSString *)(reason_) isKindOfClass:[NSString class]] ? (reason_) : @"<empty reason>") }])
#endif

#endif /* WCMacroError_h */
