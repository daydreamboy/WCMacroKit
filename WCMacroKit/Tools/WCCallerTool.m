//
//  WCCallerTool.m
//  AppTest
//
//  Created by wesley_chen on 20/12/2017.
//

#import "WCCallerTool.h"

@implementation WCCallerTool

+ (nullable id)callAndReturn:(id)sender selector:(SEL)selector {
    return [self internal_call7AndReturn:sender selector:selector param1:nil param2:nil param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (nullable id)call1AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:nil param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (nullable id)call2AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (nullable id)call3AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:param3 param4:nil param5:nil param6:nil param7:nil];
}

+ (nullable id)call4AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:nil param6:nil param7:nil];
}

+ (nullable id)call5AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:nil param7:nil];
}

+ (nullable id)call6AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:param6 param7:nil];
}

+ (nullable id)call7AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7 {
    return [self internal_call7AndReturn:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:param6 param7:param7];
}

#pragma mark -

+ (BOOL)call:(id)sender selector:(SEL)selector {
    return [self internal_call7:sender selector:selector param1:nil param2:nil param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (BOOL)call1:(id)sender selector:(SEL)selector param1:(id)param1 {
    return [self internal_call7:sender selector:selector param1:param1 param2:nil param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (BOOL)call2:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:nil param4:nil param5:nil param6:nil param7:nil];
}

+ (BOOL)call3:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:param3 param4:nil param5:nil param6:nil param7:nil];
}

+ (BOOL)call4:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:nil param6:nil param7:nil];
}

+ (BOOL)call5:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:nil param7:nil];
}

+ (BOOL)call6:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:param6 param7:nil];
}

+ (BOOL)call7:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7 {
    return [self internal_call7:sender selector:selector param1:param1 param2:param2 param3:param3 param4:param4 param5:param5 param6:param6 param7:param7];
}

#pragma mark - Private Methods

+ (nullable id)internal_call7AndReturn:(id)sender selector:(SEL)selector param1:(nullable id)param1 param2:(nullable id)param2 param3:(nullable id)param3 param4:(nullable id)param4 param5:(nullable id)param5 param6:(nullable id)param6 param7:(nullable id)param7 {
    if (![sender respondsToSelector:selector] || selector == nil) {
        return nil;
    }
    
    id returnValue = nil;
    
    typeof(param1) arg1 = param1;
    typeof(param2) arg2 = param2;
    typeof(param3) arg3 = param3;
    typeof(param4) arg4 = param4;
    typeof(param5) arg5 = param5;
    typeof(param6) arg6 = param6;
    typeof(param7) arg7 = param7;
    void *tempReturnValue = nil;
    
    @try {
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        
        if (arg7) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
            [invocation setArgument:&arg6 atIndex:7];
            [invocation setArgument:&arg7 atIndex:8];
        }
        else if (arg6) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
            [invocation setArgument:&arg6 atIndex:7];
        }
        else if (arg5) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
        }
        else if (arg4) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
        }
        else if (arg3) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
        }
        else if (arg2) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
        }
        else if (arg1) {
            [invocation setArgument:&arg1 atIndex:2];
        }
        
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
    }
    @catch (NSException *exception) {
    }
        
    returnValue = (__bridge id)tempReturnValue;
    return returnValue;
}

+ (BOOL)internal_call7:(id)sender selector:(SEL)selector param1:(nullable id)param1 param2:(nullable id)param2 param3:(nullable id)param3 param4:(nullable id)param4 param5:(nullable id)param5 param6:(nullable id)param6 param7:(nullable id)param7 {
    if (![sender respondsToSelector:selector] || selector == nil) {
        return NO;
    }
    
    BOOL success = YES;
    
    typeof(param1) arg1 = param1;
    typeof(param2) arg2 = param2;
    typeof(param3) arg3 = param3;
    typeof(param4) arg4 = param4;
    typeof(param5) arg5 = param5;
    typeof(param6) arg6 = param6;
    typeof(param7) arg7 = param7;
    
    @try {
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        
        if (arg7) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
            [invocation setArgument:&arg6 atIndex:7];
            [invocation setArgument:&arg7 atIndex:8];
        }
        else if (arg6) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
            [invocation setArgument:&arg6 atIndex:7];
        }
        else if (arg5) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
            [invocation setArgument:&arg5 atIndex:6];
        }
        else if (arg4) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
            [invocation setArgument:&arg4 atIndex:5];
        }
        else if (arg3) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
            [invocation setArgument:&arg3 atIndex:4];
        }
        else if (arg2) {
            [invocation setArgument:&arg1 atIndex:2];
            [invocation setArgument:&arg2 atIndex:3];
        }
        else if (arg1) {
            [invocation setArgument:&arg1 atIndex:2];
        }
        
        [invocation invoke];
    }
    @catch (NSException *exception) {
        success = NO;
    }
    
    return success;
}

@end
