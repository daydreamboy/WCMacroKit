//
//  ExternalFunctionImplementation.m
//  Test
//
//  Created by wesley_chen on 2021/7/9.
//

#import "ExternalFunctionImplementation.h"

NSString * __attribute__((used)) someLog(NSString *message)
{
    NSLog(@"someLog: %@", message);
    return message;
}

void __attribute__((used)) someLogWithoutReturn(NSString *message)
{
    NSLog(@"someLogWithoutReturn: %@", message);
}

@implementation ExternalFunctionImplementation

@end
