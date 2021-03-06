//
//  mk_fitpoloAdopter.h
//  mk_fitpoloCentralManager
//
//  Created by aa on 2018/12/10.
//  Copyright © 2018 mk_fitpolo. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 Custom error code
 */
typedef NS_ENUM(NSInteger, mk_customErrorCode){
    mk_bluetoothDisable = -10000,                                //Current phone Bluetooth is not available.
    mk_connectedFailed = -10001,                                 //Connection peripheral failed.
    mk_peripheralDisconnected = -10002,                          //The currently externally connected device is disconnected.
    mk_characteristicError = -10003,                             //Feature is empty.
    mk_requestPeripheralDataError = -10004,                      //Requesting bracelet data error.
    mk_paramsError = -10005,                                     //The input parameters are incorrect.
    mk_setParamsError = -10006,                                  //Setting parameter error.
    mk_getPackageError = -10007,                                 //When upgrading the firmware, the firmware data passed in is wrong.
    mk_updateError = -10008,                                     //upgrade fail.
    mk_deviceTypeUnknowError = -10009,                           //Device type error.
    mk_unsupportCommandError = -10010,                           //Device do not support the command.
    mk_deviceIsConnectingError = -10011,                         //The device is connecting and does not allow duplicate connections.
};

NS_ASSUME_NONNULL_BEGIN

@interface mk_fitpoloAdopter : NSObject

#pragma mark - blocks
+ (NSError *)getErrorWithCode:(mk_customErrorCode)code message:(NSString *)message;
+ (void)operationCentralBlePowerOffBlock:(void (^)(NSError *error))block;
+ (void)operationConnectFailedBlock:(void (^)(NSError *error))block;
+ (void)operationDisconnectedErrorBlock:(void (^)(NSError *error))block;
+ (void)operationCharacteristicErrorBlock:(void (^)(NSError *error))block;
+ (void)operationRequestDataErrorBlock:(void (^)(NSError *error))block;
+ (void)operationParamsErrorBlock:(void (^)(NSError *error))block;
+ (void)operationSetParamsErrorBlock:(void (^)(NSError *error))block;
+ (void)operationDeviceTypeErrorBlock:(void (^)(NSError *error))block;
+ (void)operationUnsupportCommandErrorBlock:(void (^)(NSError *error))block;
+ (void)operationGetPackageDataErrorBlock:(void (^)(NSError *error))block;
+ (void)operationUpdateErrorBlock:(void (^)(NSError *error))block;
+ (void)operationConnectingErrorBlock:(void (^)(NSError *error))block;
+ (void)operationSetParamsResult:(id)returnData
                        sucBlock:(void (^)(id returnData))sucBlock
                     failedBlock:(void (^)(NSError *error))failedBlock;

#pragma mark - parser
+ (NSInteger)getDecimalWithHex:(NSString *)content range:(NSRange)range;
+ (NSString *)getDecimalStringWithHex:(NSString *)content range:(NSRange)range;
+ (NSArray *)interceptionOfArray:(NSArray *)originalArray subRange:(NSRange)range;
+ (NSData *)getCrc16VerifyCode:(NSData *)data;
+ (NSString *)hexStringFromData:(NSData *)sourceData;
+ (NSString *)getTimeStringWithDate:(NSDate *)date;
+ (NSData *)stringToData:(NSString *)dataString;
+ (BOOL)isMacAddress:(NSString *)macAddress;
+ (BOOL)isMacAddressLowFour:(NSString *)lowFour;
+ (BOOL)isUUIDString:(NSString *)uuid;
+ (BOOL)checkIdenty:(NSString *)identy;

@end

NS_ASSUME_NONNULL_END
