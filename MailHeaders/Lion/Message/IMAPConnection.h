/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import <Message/Connection.h>

@class IMAPAccount, IMAPGateway, IMAPMailbox, InvocationQueue, NSMutableDictionary, NSMutableSet, NSRecursiveLock, NSString;

@interface IMAPConnection : Connection
{
    NSRecursiveLock *_imapConnectionLock;
    IMAPAccount *_IMAPAccount;
    unsigned long long _capabilityFlags;
    int _connectionState;
    NSMutableSet *_capabilities;
    NSString *_separatorChar;
    NSString *_selectedMailbox;
    IMAPMailbox *_selectedIMAPMailbox;
    BOOL _selectedMailboxIsReadOnly;
    BOOL _canStartIdle;
    unsigned long long _commandNumber;
    unsigned int _readBufferSize;
    double _expirationTime;
    InvocationQueue *_streamEventQueue;
    NSMutableDictionary *_unhandledTaggedResponses;
    unsigned long long _fetchSizeNextReadingIndex;
    double _fetchSizeRollingAverage;
    BOOL _fetchSizeFirstTime;
    BOOL _fetchSizeFilledHistory;
    double _fetchSizeRecentTimes[8];
    IMAPGateway *_gateway;
    NSRecursiveLock *_validatingLock;
    unsigned long long _lastIdleSequenceNumber;
    unsigned long long _lastIdleSessionNumber;
    BOOL _executingInternalReconnect;
    unsigned long long _numSuccessfulOperationsSinceLastFlush;
}

+ (void)initialize;
+ (BOOL)automaticallyNotifiesObserversForKey:(id)arg1;
+ (id)keyPathsForValuesAffecting_gateway;
+ (void)_setReadSizeParameters;
- (id)initWithPendingGateway:(BOOL)arg1 account:(id)arg2;
- (id)init;
- (void)dealloc;
- (void)finalize;
- (id)displayName;
- (BOOL)reconnect;
- (void)_setupConnection;
- (BOOL)_teardownConnectionWithResult:(BOOL)arg1;
- (void)disconnectAndNotify:(BOOL)arg1;
- (void)disconnect;
- (void)quit;
- (BOOL)_tryToStartValidating;
@property BOOL isValidating;
@property(retain) IMAPGateway *gateway; // @synthesize gateway=_gateway;
- (id)_gateway;
- (int)connectionState;
- (int)currentConnectionState;
- (void)_transitionToState:(int)arg1;
- (void)_transitionToState:(int)arg1 selectedMailbox:(id)arg2 readOnly:(BOOL)arg3;
- (void)_setSelectedMailbox:(id)arg1;
- (id)mailboxNameIfSelected:(BOOL)arg1;
@property(retain) IMAPMailbox *selectedIMAPMailbox;
- (BOOL)needsSelectForMailboxName:(id)arg1 gateway:(id)arg2;
- (BOOL)isValid;
- (BOOL)isValidPreferringNetworkCheck:(BOOL)arg1;
- (BOOL)isDisconnected;
- (BOOL)shouldExecuteOperationsImmediately;
- (void)_flushSuccessfulOperationMessageTracerInfoIfNeededOrForceFlush:(BOOL)arg1;
- (void)_logMessageTracerInfoForOperationIfNeededForOperationStateProblemDescription:(id)arg1;
- (BOOL)prepareAndExecuteOperation:(id)arg1 outWrongState:(char *)arg2;
- (BOOL)executeClientOperation:(id)arg1;
- (BOOL)_sendCommand:(id)arg1 response:(id *)arg2;
- (void)_socketDiedError:(id *)arg1;
- (BOOL)_writeData:(id)arg1 dontLogBytesInRange:(struct _NSRange)arg2 error:(id *)arg3;
- (BOOL)_readLineIntoData:(id)arg1 error:(id *)arg2;
- (BOOL)_readBytesIntoData:(id)arg1 desiredLength:(unsigned long long)arg2 error:(id *)arg3;
- (id)_copyNextServerResponse:(id *)arg1;
- (id)_copyNextTaggedOrContinuationResponseForCommand:(id)arg1;
- (id)_copyNextTaggedOrContinuationResponseForCommand:(id)arg1 exists:(unsigned long long *)arg2;
- (id)_errorForResponse:(id)arg1 operation:(id)arg2;
- (id)capabilities;
- (BOOL)supportsCapability:(unsigned long long)arg1;
- (void)updateCanStartIdle:(BOOL)arg1;
- (void)_clearCapabilities;
- (void)_addToCapabilities:(id)arg1;
- (void)_fetchCapabilitiesIfNeeded;
- (BOOL)executeCapability:(id)arg1;
- (void)_sendID;
- (BOOL)executeID:(id)arg1;
- (BOOL)executeNoop:(id)arg1;
- (id)authenticationMechanisms;
- (BOOL)authenticateUsingAccount:(id)arg1;
- (BOOL)_reauthenticate;
- (BOOL)_authenticateUsingAccount:(id)arg1 authenticator:(id)arg2;
- (long long)_authenticateUsingHostname:(id)arg1 username:(id)arg2 password:(id)arg3 authScheme:(id)arg4 authenticator:(id)arg5;
- (BOOL)executeAuthenticate:(id)arg1;
- (BOOL)_startTLSForHostname:(id)arg1 onPort:(unsigned int)arg2 securityLayerType:(long long)arg3 accountClass:(Class)arg4;
- (long long)_startTLSForSecurityLayerType:(long long)arg1;
- (BOOL)executeStartTLS:(id)arg1;
- (id)_getServerAlertErrorFromResponse:(id)arg1 forCommand:(id)arg2;
- (BOOL)_loginWithUsername:(id)arg1 password:(id)arg2;
- (BOOL)executeLogin:(id)arg1;
- (BOOL)executeLogout:(id)arg1;
- (id)separatorChar;
- (void)setSeparatorChar:(id)arg1;
- (BOOL)executeListOrLSub:(id)arg1;
- (BOOL)executeUnselect:(id)arg1;
- (void)handleStreamEvent:(id)arg1;
- (void)_handleBytesAvailable;
- (BOOL)isIdle;
- (BOOL)startIdle;
- (BOOL)executeIdle:(id)arg1;
- (BOOL)executeDone:(id)arg1;
- (BOOL)executeUIDExpunge:(id)arg1;
- (BOOL)executeStatus:(id)arg1;
- (BOOL)executeSubscribeOperation:(id)arg1;
- (BOOL)executeSelectOperation:(id)arg1;
- (BOOL)executeUIDSearch:(id)arg1;
- (BOOL)executeUIDStore:(id)arg1;
- (id)_responseFromSendingOperation:(id)arg1 tryCreate:(char *)arg2;
- (BOOL)executeUIDCopy:(id)arg1;
- (BOOL)executeAppend:(id)arg1;
- (BOOL)executeNamespace:(id)arg1;
- (void)resetTimingHistory;
- (double)updatedRecentAverageWithNewValue:(double)arg1;
- (void)setReadBufferSizeFromElapsedTime:(double)arg1 bytesRead:(unsigned int)arg2;
- (unsigned int)readBufferSize;
- (void)setReadBufferSize:(unsigned int)arg1;
- (BOOL)executeFetch:(id)arg1;
- (id)description;
- (BOOL)_correctMailboxIsSelectedForOperation:(id)arg1;
- (id)_responseFromSendingOperation:(id)arg1;
- (BOOL)_commandShouldBeSentAgainOnError:(int)arg1;
- (BOOL)_isTemporaryError:(id)arg1;
- (void)_setError:(id)arg1 forCommand:(id)arg2;
- (BOOL)_recordUntaggedResponse:(id)arg1 forOperation:(id)arg2;
- (BOOL)_recordUntaggedResponse:(id)arg1 forOperation:(id)arg2 exists:(unsigned long long *)arg3 fromIDLE:(BOOL)arg4;
- (void)_recordResponse:(id)arg1 forOperation:(id)arg2;
- (BOOL)_recordMailboxResponse:(id)arg1 forOperation:(id)arg2;
- (BOOL)_recordMailboxResponse:(id)arg1 forOperation:(id)arg2 exists:(unsigned long long *)arg3 fromIDLE:(BOOL)arg4;
@property BOOL canStartIdle; // @synthesize canStartIdle=_canStartIdle;
@property(retain) NSRecursiveLock *validatingLock; // @synthesize validatingLock=_validatingLock;
@property IMAPAccount *account; // @synthesize account=_IMAPAccount;
- (BOOL)_readDataOfLength:(long long)arg1 intoData:(id)arg2 error:(id *)arg3;
- (BOOL)_isFetchResponseValid:(id)arg1;

@end

