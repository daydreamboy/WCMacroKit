//
//  WCMacroThread.h
//  WCMacroKit
//
//  Created by wesley_chen on 2020/5/23.
//

#ifndef WCMacroThread_h
#define WCMacroThread_h

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

/**
 Create a semaphore as a lock
 */
#define SEMA_LOCK_INIT \
static dispatch_semaphore_t sLock; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
    sLock = dispatch_semaphore_create(1); \
});

/**
 Use the semaphore lock
 
 @param ... the code to protect
 @discussion This macro must be used in company with SEMA_LOCK_INIT
 @code
 + (nullable NSString *)appExecutableUUID {
    static NSString *sUUID;
    SEMA_LOCK_INIT
    
    if (!sUUID) {
        SMEA_LOCK(
            sUUID = <Get your UUID>;
        );
    }

    return sUUID;
 }
 @endcode
 */
#define SEMA_LOCK(...) \
dispatch_semaphore_wait(sLock, DISPATCH_TIME_FOREVER); \
__VA_ARGS__ \
dispatch_semaphore_signal(sLock);


#endif /* WCMacroThread_h */
