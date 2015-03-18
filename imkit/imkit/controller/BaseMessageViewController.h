//
//  BaseMessageViewController.h
//  imkit
//
//  Created by houxh on 15/3/17.
//  Copyright (c) 2015年 beetle. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <imsdk/IMService.h>
#import "IMessage.h"

//基类处理tableview相关的数据
@interface BaseMessageViewController : UIViewController<MessageObserver>
@property(nonatomic, assign) int64_t currentUID;
@property(nonatomic, assign) int64_t peerUID;
@property(nonatomic, copy) NSString *peerName;


//protected
@property(nonatomic) NSMutableArray *messageArray;
@property(nonatomic) NSMutableArray *timestamps;
@property(nonatomic) NSMutableArray *messages;

@property(nonatomic) UIRefreshControl *refreshControl;
@property(nonatomic) UITableView *tableView;


//是否只展示文本消息
@property(nonatomic) BOOL textMode;


//protected
- (void)addObserver;
- (void)removeObserver;

- (void)resendMessage:(IMessage*)message;
- (void)sendAudioMessage:(NSString*)path second:(int)second;
- (void)sendImageMessage:(UIImage*)image;
- (void)sendTextMessage:(NSString*)text;

- (void)sendMessage:(IMessage*)msg;
- (void)loadConversationData;
- (void)pullToRefresh;

- (void)reloadMessage:(int)msgLocalID;
- (void)insertMessage:(IMessage*)msg;
- (void)scrollToBottomAnimated:(BOOL)animated;

- (IMessage*)messageForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)timestampForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath*)getIndexPathById:(int)msgLocalID;

- (NSString *)getWeekDayString:(NSInteger)iDay;
- (BOOL)isSameDay:(NSDate*)date1 other:(NSDate*)date2 ;
- (BOOL)isYestoday:(NSDate*)date1 today:(NSDate*)date2 ;
- (BOOL)isBeforeYestoday:(NSDate*)date1 today:(NSDate*)date2;
- (BOOL)isInWeek:(NSDate*)date1 today:(NSDate*)date2;
- (BOOL)isInMonth:(NSDate*)date1 today:(NSDate*)date2;
- (NSDateComponents*)getComponentOfDate:(NSDate *)date ;
- (NSString *)getConversationTimeString:(NSDate *)date;

+ (void)playMessageReceivedSound;
+ (void)playMessageSentSound;

@end