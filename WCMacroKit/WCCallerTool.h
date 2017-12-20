//
//  WCCallerTool.h
//  AppTest
//
//  Created by wesley_chen on 20/12/2017.
//

#import <Foundation/Foundation.h>

/**
 A runtime tool for call any object's methods with mutiple parameters (Counterpart for macro DELEGATE_SAFE_CALL)
 Caveat:
    - parameter NOT suppert basic type (e.g, int, CGFloat), box them firstly
 */
@interface WCCallerTool : NSObject

+ (id)callAndReturn:(id)sender selector:(SEL)selector;
+ (id)call1AndReturn:(id)sender selector:(SEL)selector param1:(id)param1;
+ (id)call2AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2;
+ (id)call3AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3;
+ (id)call4AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4;
+ (id)call5AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5;
+ (id)call6AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6;
+ (id)call7AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7;

+ (void)call:(id)sender selector:(SEL)selector;
+ (void)call1:(id)sender selector:(SEL)selector param1:(id)param1;
+ (void)call2:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2;
+ (void)call3:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3;
+ (void)call4:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4;
+ (void)call5:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5;
+ (void)call6:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6;
+ (void)call7:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7;

@end
