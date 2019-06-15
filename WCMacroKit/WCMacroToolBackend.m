//
//  WCMacroToolBackend.m
//  WCMacroKit
//
//  Created by wesley_chen on 2019/3/9.
//

#import "WCMacroToolBackend.h"

@implementation WCMacroToolBackend

+ (NSArray *)arrayFromVaList:(va_list)ap {
    id obj;
    NSMutableArray *array = [NSMutableArray array];
    
    while ((obj = va_arg(ap, id))) {
        [array addObject:obj];
    }
    
    return array;
}

#pragma mark - NSDictionary

#pragma mark > Merge

+ (nullable NSDictionary *)mergedDictionaryWithDictionary1:(nullable NSDictionary *)dictionary1 dictionary2:(nullable NSDictionary *)dictionary2 allowMutable:(BOOL)allowMutable {
    if (dictionary1 && ![dictionary1 isKindOfClass:[NSDictionary class]]) {
        return nil;
    }
    
    if (dictionary2 && ![dictionary2 isKindOfClass:[NSDictionary class]]) {
        return nil;
    }
    
    NSMutableDictionary *dictM = [NSMutableDictionary dictionary];
    if (dictionary1) {
        [dictM addEntriesFromDictionary:dictionary1];
    }
    if (dictionary2) {
        [dictM addEntriesFromDictionary:dictionary2];
    }
    
    return allowMutable ? dictM : [dictM copy];
}

@end
