/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "RemoteStoreQuota.h"

@class NSPopUpButton, NSTextField, NSView, QuotaBar;

@interface IMAPQuota : RemoteStoreQuota
{
    NSPopUpButton *_quotaPopup;
    NSTextField *_quotaPopupLabel;
    NSView *_quotaContainerView;
    QuotaBar *_quotaBar;
    NSTextField *_capacityField;
    NSTextField *_statusField;
    double _spaceUnderQuotaPopup;
}

- (id)initWithAccount:(id)arg1;
- (void)awakeFromNib;
- (void)dealloc;
- (Class)engineClass;
- (BOOL)tableShouldIncludeMailbox:(id)arg1;
- (void)quotaPopupChanged:(id)arg1;
- (id)_selectedQuotaName;
- (void)_updateQuotaBarWithSize:(unsigned long long)arg1 maxSize:(unsigned long long)arg2 count:(long long)arg3 maxCount:(long long)arg4;
- (void)_updateStatusField;
- (void)_engineStatusChanged:(id)arg1;
- (void)_updateQuotaPopupWithQuotaNames:(id)arg1;
- (void)engineDidFinish;
- (void)engineUpdated:(id)arg1;
- (void)_updateUIForQuotaName:(id)arg1 updateTable:(BOOL)arg2;
- (id)_stringForSize:(unsigned long long)arg1 andCount:(long long)arg2 isCapacity:(BOOL)arg3;

@end
