//
//  WCCallerTool.h
//  AppTest
//
//  Created by wesley_chen on 20/12/2017.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A runtime tool for call any object's methods with mutiple parameters (Counterpart for macro DELEGATE_SAFE_CALL)
 Caveat:
    - parameter NOT suppert basic type (e.g, int, CGFloat), box them firstly
 */
@interface WCCallerTool : NSObject

+ (nullable id)callAndReturn:(id)sender selector:(SEL)selector;
+ (nullable id)call1AndReturn:(id)sender selector:(SEL)selector param1:(id)param1;
+ (nullable id)call2AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2;
+ (nullable id)call3AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3;
+ (nullable id)call4AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4;
+ (nullable id)call5AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5;
+ (nullable id)call6AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6;
+ (nullable id)call7AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7;

+ (BOOL)call:(id)sender selector:(SEL)selector;
+ (BOOL)call1:(id)sender selector:(SEL)selector param1:(id)param1;
+ (BOOL)call2:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2;
+ (BOOL)call3:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3;
+ (BOOL)call4:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4;
+ (BOOL)call5:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5;
+ (BOOL)call6:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6;
+ (BOOL)call7:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7;

@end

NS_ASSUME_NONNULL_END
