// Objective-C API for talking to github.com/centrifugal/centrifuge-mobile Go package.
//   gobind -lang=objc github.com/centrifugal/centrifuge-mobile
//
// File is generated by gobind. Do not edit.

#ifndef __Centrifuge_H__
#define __Centrifuge_H__

@import Foundation;
#include "Universe.objc.h"


@class CentrifugeClient;
@class CentrifugeClientInfo;
@class CentrifugeConfig;
@class CentrifugeConnectContext;
@class CentrifugeCredentials;
@class CentrifugeDisconnectContext;
@class CentrifugeErrorContext;
@class CentrifugeEventHandler;
@class CentrifugeHistoryData;
@class CentrifugeMessage;
@class CentrifugePresenceData;
@class CentrifugePrivateRequest;
@class CentrifugePrivateSign;
@class CentrifugeSub;
@class CentrifugeSubEventHandler;
@class CentrifugeSubscribeErrorContext;
@class CentrifugeSubscribeSuccessContext;
@class CentrifugeUnsubscribeContext;
@protocol CentrifugeConnectHandler;
@class CentrifugeConnectHandler;
@protocol CentrifugeDisconnectHandler;
@class CentrifugeDisconnectHandler;
@protocol CentrifugeErrorHandler;
@class CentrifugeErrorHandler;
@protocol CentrifugeJoinHandler;
@class CentrifugeJoinHandler;
@protocol CentrifugeLeaveHandler;
@class CentrifugeLeaveHandler;
@protocol CentrifugeMessageHandler;
@class CentrifugeMessageHandler;
@protocol CentrifugePrivateSubHandler;
@class CentrifugePrivateSubHandler;
@protocol CentrifugeRefreshHandler;
@class CentrifugeRefreshHandler;
@protocol CentrifugeSubscribeErrorHandler;
@class CentrifugeSubscribeErrorHandler;
@protocol CentrifugeSubscribeSuccessHandler;
@class CentrifugeSubscribeSuccessHandler;
@protocol CentrifugeUnsubscribeHandler;
@class CentrifugeUnsubscribeHandler;

@protocol CentrifugeConnectHandler <NSObject>
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectContext*)p1;
@end

@protocol CentrifugeDisconnectHandler <NSObject>
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectContext*)p1;
@end

@protocol CentrifugeErrorHandler <NSObject>
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorContext*)p1;
@end

@protocol CentrifugeJoinHandler <NSObject>
- (void)onJoin:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@protocol CentrifugeLeaveHandler <NSObject>
- (void)onLeave:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

@protocol CentrifugeMessageHandler <NSObject>
- (void)onMessage:(CentrifugeSub*)p0 p1:(CentrifugeMessage*)p1;
@end

@protocol CentrifugePrivateSubHandler <NSObject>
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateRequest*)p1 error:(NSError**)error;
@end

@protocol CentrifugeRefreshHandler <NSObject>
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

@protocol CentrifugeSubscribeErrorHandler <NSObject>
- (void)onSubscribeError:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeErrorContext*)p1;
@end

@protocol CentrifugeSubscribeSuccessHandler <NSObject>
- (void)onSubscribeSuccess:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeSuccessContext*)p1;
@end

@protocol CentrifugeUnsubscribeHandler <NSObject>
- (void)onUnsubscribe:(CentrifugeSub*)p0 p1:(CentrifugeUnsubscribeContext*)p1;
@end

/**
 * Client describes client connection to Centrifugo server.
 */
@interface CentrifugeClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * Close closes Client connection and cleans ups everything.
 */
- (void)close;
/**
 * Connect connects to Centrifugo and sends connect message to authenticate.
 */
- (BOOL)connect:(NSError**)error;
/**
 * Disconnect client from Centrifugo.
 */
- (BOOL)disconnect:(NSError**)error;
/**
 * Subscribe allows to subscribe on channel.
 */
- (CentrifugeSub*)subscribe:(NSString*)channel events:(CentrifugeSubEventHandler*)events error:(NSError**)error;
/**
 * SubscribeAsync allows to subscribe on channel.
 */
- (CentrifugeSub*)subscribeAsync:(NSString*)channel events:(CentrifugeSubEventHandler*)events;
@end

@interface CentrifugeClientInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSString*)client;
- (void)setClient:(NSString*)v;
- (NSString*)defaultInfo;
- (void)setDefaultInfo:(NSString*)v;
- (NSString*)channelInfo;
- (void)setChannelInfo:(NSString*)v;
@end

/**
 * Config contains various client options.
 */
@interface CentrifugeConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (long)timeoutMilliseconds;
- (void)setTimeoutMilliseconds:(long)v;
- (NSString*)privateChannelPrefix;
- (void)setPrivateChannelPrefix:(NSString*)v;
- (BOOL)websocketCompression;
- (void)setWebsocketCompression:(BOOL)v;
- (BOOL)ping;
- (void)setPing:(BOOL)v;
- (long)pingMilliseconds;
- (void)setPingMilliseconds:(long)v;
- (long)pongMilliseconds;
- (void)setPongMilliseconds:(long)v;
@end

/**
 * ConnectContext is a connect event context passed to OnConnect callback.
 */
@interface CentrifugeConnectContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
@end

/**
 * Credentials describe client connection parameters.
 */
@interface CentrifugeCredentials : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
/**
 * NewCredentials initializes Credentials.
 */
- (instancetype)init:(NSString*)user timestamp:(NSString*)timestamp info:(NSString*)info token:(NSString*)token;
- (NSString*)user;
- (void)setUser:(NSString*)v;
- (NSString*)timestamp;
- (void)setTimestamp:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
- (NSString*)token;
- (void)setToken:(NSString*)v;
@end

/**
 * DisconnectContext is a disconnect event context passed to OnDisconnect callback.
 */
@interface CentrifugeDisconnectContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)reason;
- (void)setReason:(NSString*)v;
- (BOOL)reconnect;
- (void)setReconnect:(BOOL)v;
@end

/**
 * ErrorContext is an error event context passed to OnError callback.
 */
@interface CentrifugeErrorContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)error;
- (void)setError:(NSString*)v;
@end

/**
 * EventHandler has all event handlers for client.
 */
@interface CentrifugeEventHandler : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
/**
 * NewEventHandler initializes new EventHandler.
 */
- (instancetype)init;
/**
 * OnConnect is a function to handle connect event.
 */
- (void)onConnect:(id<CentrifugeConnectHandler>)handler;
/**
 * OnDisconnect is a function to handle disconnect event.
 */
- (void)onDisconnect:(id<CentrifugeDisconnectHandler>)handler;
/**
 * OnError is a function to handle critical protocol errors manually.
 */
- (void)onError:(id<CentrifugeErrorHandler>)handler;
/**
 * OnPrivateSub needed to handle private channel subscriptions.
 */
- (void)onPrivateSub:(id<CentrifugePrivateSubHandler>)handler;
/**
 * OnRefresh handles refresh event when client's credentials expired and must be refreshed.
 */
- (void)onRefresh:(id<CentrifugeRefreshHandler>)handler;
@end

@interface CentrifugeHistoryData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (CentrifugeMessage*)messageAt:(long)i;
- (long)numMessages;
@end

@interface CentrifugeMessage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)uid;
- (void)setUID:(NSString*)v;
- (CentrifugeClientInfo*)info;
- (void)setInfo:(CentrifugeClientInfo*)v;
- (NSString*)channel;
- (void)setChannel:(NSString*)v;
- (NSString*)data;
- (void)setData:(NSString*)v;
- (NSString*)client;
- (void)setClient:(NSString*)v;
@end

@interface CentrifugePresenceData : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (CentrifugeClientInfo*)clientAt:(long)i;
- (long)numClients;
@end

/**
 * PrivateRequest contains info required to create PrivateSign when client
wants to subscribe on private channel.
 */
@interface CentrifugePrivateRequest : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)clientID;
- (void)setClientID:(NSString*)v;
- (NSString*)channel;
- (void)setChannel:(NSString*)v;
@end

/**
 * Private sign confirmes that client can subscribe on private channel.
 */
@interface CentrifugePrivateSign : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)sign;
- (void)setSign:(NSString*)v;
- (NSString*)info;
- (void)setInfo:(NSString*)v;
@end

/**
 * Sub describes client subscription to channel.
 */
@interface CentrifugeSub : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
/**
 * Channel returns subscription channel.
 */
- (NSString*)channel;
/**
 * History allows to extract channel history.
 */
- (CentrifugeHistoryData*)history:(NSError**)error;
/**
 * Presence allows to extract presence information for channel.
 */
- (CentrifugePresenceData*)presence:(NSError**)error;
/**
 * Publish allows to publish JSON encoded data to subscription channel.
 */
- (BOOL)publish:(NSData*)data error:(NSError**)error;
/**
 * Subscribe allows to subscribe again after unsubscribing.
 */
- (BOOL)subscribe:(NSError**)error;
/**
 * Unsubscribe allows to unsubscribe from channel.
 */
- (BOOL)unsubscribe:(NSError**)error;
@end

/**
 * SubEventHandler contains callback functions that will be called when
corresponding event happens with subscription to channel.
 */
@interface CentrifugeSubEventHandler : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
/**
 * NewSubEventHandler initializes new SubEventHandler.
 */
- (instancetype)init;
/**
 * OnJoin allows to set JoinHandler to SubEventHandler.
 */
- (void)onJoin:(id<CentrifugeJoinHandler>)handler;
/**
 * OnLeave allows to set LeaveHandler to SubEventHandler.
 */
- (void)onLeave:(id<CentrifugeLeaveHandler>)handler;
/**
 * OnMessage allows to set MessageHandler to SubEventHandler.
 */
- (void)onMessage:(id<CentrifugeMessageHandler>)handler;
/**
 * OnSubscribeError allows to set SubscribeErrorHandler to SubEventHandler.
 */
- (void)onSubscribeError:(id<CentrifugeSubscribeErrorHandler>)handler;
/**
 * OnSubscribeSuccess allows to set SubscribeSuccessHandler to SubEventHandler.
 */
- (void)onSubscribeSuccess:(id<CentrifugeSubscribeSuccessHandler>)handler;
/**
 * OnUnsubscribe allows to set UnsubscribeHandler to SubEventHandler.
 */
- (void)onUnsubscribe:(id<CentrifugeUnsubscribeHandler>)handler;
@end

/**
 * SubscribeErrorContext is a subscribe error event context passed to event callback.
 */
@interface CentrifugeSubscribeErrorContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)error;
- (void)setError:(NSString*)v;
@end

/**
 * SubscribeSuccessContext is a subscribe success event context passed to event callback.
 */
@interface CentrifugeSubscribeSuccessContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (BOOL)resubscribed;
- (void)setResubscribed:(BOOL)v;
- (BOOL)recovered;
- (void)setRecovered:(BOOL)v;
@end

/**
 * UnsubscribeContext is a context passed to unsubscribe event callback.
 */
@interface CentrifugeUnsubscribeContext : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
@end

FOUNDATION_EXPORT const int64_t CentrifugeCLOSED;
FOUNDATION_EXPORT const int64_t CentrifugeCONNECTED;
FOUNDATION_EXPORT const int64_t CentrifugeCONNECTING;
FOUNDATION_EXPORT const int64_t CentrifugeDISCONNECTED;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultPingMilliseconds;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultPongMilliseconds;
FOUNDATION_EXPORT NSString* const CentrifugeDefaultPrivateChannelPrefix;
FOUNDATION_EXPORT const int64_t CentrifugeDefaultTimeoutMilliseconds;
FOUNDATION_EXPORT const int64_t CentrifugeNEW;
FOUNDATION_EXPORT const int64_t CentrifugeSUBERROR;
FOUNDATION_EXPORT const int64_t CentrifugeSUBSCRIBED;
FOUNDATION_EXPORT const int64_t CentrifugeSUBSCRIBING;
FOUNDATION_EXPORT const int64_t CentrifugeUNSUBSCRIBED;

@interface Centrifuge : NSObject
+ (NSError*) errBadPublishStatus;
+ (void) setErrBadPublishStatus:(NSError*)v;

+ (NSError*) errBadSubscribeStatus;
+ (void) setErrBadSubscribeStatus:(NSError*)v;

+ (NSError*) errBadUnsubscribeStatus;
+ (void) setErrBadUnsubscribeStatus:(NSError*)v;

+ (NSError*) errClientDisconnected;
+ (void) setErrClientDisconnected:(NSError*)v;

+ (NSError*) errClientExpired;
+ (void) setErrClientExpired:(NSError*)v;

+ (NSError*) errClientStatus;
+ (void) setErrClientStatus:(NSError*)v;

+ (NSError*) errDuplicateWaiter;
+ (void) setErrDuplicateWaiter:(NSError*)v;

+ (NSError*) errInvalidMessage;
+ (void) setErrInvalidMessage:(NSError*)v;

+ (NSError*) errReconnectFailed;
+ (void) setErrReconnectFailed:(NSError*)v;

+ (NSError*) errTimeout;
+ (void) setErrTimeout:(NSError*)v;

+ (NSError*) errWaiterClosed;
+ (void) setErrWaiterClosed:(NSError*)v;

@end

/**
 * DefaultConfig returns Config with default options.
 */
FOUNDATION_EXPORT CentrifugeConfig* CentrifugeDefaultConfig(void);

/**
 * New initializes Client struct. It accepts URL to Centrifugo server,
connection Credentials, EventHandler and Config.
 */
FOUNDATION_EXPORT CentrifugeClient* CentrifugeNew(NSString* u, CentrifugeCredentials* creds, CentrifugeEventHandler* events, CentrifugeConfig* config);

/**
 * NewCredentials initializes Credentials.
 */
FOUNDATION_EXPORT CentrifugeCredentials* CentrifugeNewCredentials(NSString* user, NSString* timestamp, NSString* info, NSString* token);

/**
 * NewEventHandler initializes new EventHandler.
 */
FOUNDATION_EXPORT CentrifugeEventHandler* CentrifugeNewEventHandler(void);

/**
 * NewSubEventHandler initializes new SubEventHandler.
 */
FOUNDATION_EXPORT CentrifugeSubEventHandler* CentrifugeNewSubEventHandler(void);

/**
 * Timestamp is helper function to get current timestamp as
string - i.e. in a format Centrifugo expects. Actually in
most cases you need an analogue of this function on your
app backend when generating client connection token.
 */
FOUNDATION_EXPORT NSString* CentrifugeTimestamp(void);

@class CentrifugeConnectHandler;

@class CentrifugeDisconnectHandler;

@class CentrifugeErrorHandler;

@class CentrifugeJoinHandler;

@class CentrifugeLeaveHandler;

@class CentrifugeMessageHandler;

@class CentrifugePrivateSubHandler;

@class CentrifugeRefreshHandler;

@class CentrifugeSubscribeErrorHandler;

@class CentrifugeSubscribeSuccessHandler;

@class CentrifugeUnsubscribeHandler;

/**
 * ConnectHandler is an interface describing how to handle connect event.
 */
@interface CentrifugeConnectHandler : NSObject <goSeqRefInterface, CentrifugeConnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onConnect:(CentrifugeClient*)p0 p1:(CentrifugeConnectContext*)p1;
@end

/**
 * DisconnectHandler is an interface describing how to handle disconnect event.
 */
@interface CentrifugeDisconnectHandler : NSObject <goSeqRefInterface, CentrifugeDisconnectHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onDisconnect:(CentrifugeClient*)p0 p1:(CentrifugeDisconnectContext*)p1;
@end

/**
 * ErrorHandler is an interface describing how to handle error event.
 */
@interface CentrifugeErrorHandler : NSObject <goSeqRefInterface, CentrifugeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onError:(CentrifugeClient*)p0 p1:(CentrifugeErrorContext*)p1;
@end

/**
 * JoinHandler is a function to handle join messages.
 */
@interface CentrifugeJoinHandler : NSObject <goSeqRefInterface, CentrifugeJoinHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onJoin:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

/**
 * LeaveHandler is a function to handle leave messages.
 */
@interface CentrifugeLeaveHandler : NSObject <goSeqRefInterface, CentrifugeLeaveHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onLeave:(CentrifugeSub*)p0 p1:(CentrifugeClientInfo*)p1;
@end

/**
 * MessageHandler is a function to handle messages in channels.
 */
@interface CentrifugeMessageHandler : NSObject <goSeqRefInterface, CentrifugeMessageHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onMessage:(CentrifugeSub*)p0 p1:(CentrifugeMessage*)p1;
@end

/**
 * PrivateSubHandler is an interface describing how to handle private subscription request.
 */
@interface CentrifugePrivateSubHandler : NSObject <goSeqRefInterface, CentrifugePrivateSubHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugePrivateSign*)onPrivateSub:(CentrifugeClient*)p0 p1:(CentrifugePrivateRequest*)p1 error:(NSError**)error;
@end

/**
 * RefreshHandler is an interface describing how to connection credentials refresh event.
 */
@interface CentrifugeRefreshHandler : NSObject <goSeqRefInterface, CentrifugeRefreshHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (CentrifugeCredentials*)onRefresh:(CentrifugeClient*)p0 error:(NSError**)error;
@end

/**
 * SubscribeErrorHandler is a function to handle subscribe error event.
 */
@interface CentrifugeSubscribeErrorHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeErrorHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeError:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeErrorContext*)p1;
@end

/**
 * SubscribeSuccessHandler is a function to handle subscribe success event.
 */
@interface CentrifugeSubscribeSuccessHandler : NSObject <goSeqRefInterface, CentrifugeSubscribeSuccessHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onSubscribeSuccess:(CentrifugeSub*)p0 p1:(CentrifugeSubscribeSuccessContext*)p1;
@end

/**
 * UnsubscribeHandler is a function to handle unsubscribe event.
 */
@interface CentrifugeUnsubscribeHandler : NSObject <goSeqRefInterface, CentrifugeUnsubscribeHandler> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onUnsubscribe:(CentrifugeSub*)p0 p1:(CentrifugeUnsubscribeContext*)p1;
@end

#endif
