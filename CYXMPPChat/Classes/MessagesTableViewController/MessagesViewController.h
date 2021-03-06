//
//  MessagesViewController.h
//
//  Created by Jesse Squires on 2/12/13.
//  Copyright (c) 2013 Hexed Bits. All rights reserved.
//
//
//  Largely based on work by Sam Soffes
//  https://github.com/soffes
//
//  SSMessagesViewController
//  https://github.com/soffes/ssmessagesviewcontroller
//
//
//  The MIT License
//  Copyright (c) 2013 Jesse Squires
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
//  associated documentation files (the "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
//  following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
//  LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
//  OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import "BubbleMessageCell.h"
#import "MessageSoundEffect.h"
#import "FacialView.h"
#import "StyledPageControl.h"

@class MessageInputView;

@interface MessagesViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UITextViewDelegate,UIGestureRecognizerDelegate,facialViewDelegate>

@property (strong, nonatomic) UITableView *tableView;
@property (retain, nonatomic) MessageInputView *inputView;
@property (assign, nonatomic) CGFloat previousTextViewContentHeight;

@property BOOL isLongPressOnCell;

@property BOOL isSendingMsg;//发送中

#pragma mark - Actions
- (void)sendPressed:(UIButton *)sender withText:(NSString *)text;
- (void)sendPressed:(UIButton *)sender;
- (void)buttonTouchBegin:(UIButton *)sender;
- (void)buttonTouchEnd:(UIButton *)sender;
- (void)handleSwipe:(UIGestureRecognizer *)guestureRecognizer;
-(void)functionButtonAction:(id)sender;

-(void)setUpInputView;

-(void)getMoreMessageData;
-(void)showLoadMoreDataTipsView:(BOOL)isShow;

-(void)checkUserInfo:(id)sender;

#pragma mark - Messages view controller
- (BubbleMessageStyle)messageStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)textForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)dateForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIImage *)contentImageForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIImage *)userImageForRowAtIndexPath:(NSIndexPath *)indexPath;

- (UIView *)cellContentViewForRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)cellHeightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSString *)contentSendTimeForRowAtIndexPath:(NSIndexPath *)indexPath;
- (int)contentTypeTimeForRowAtIndexPath:(NSIndexPath *)indexPath;

- (void)finishSend;
- (void)setBackgroundColor:(UIColor *)color;
- (void)scrollToBottomAnimated:(BOOL)animated;

#pragma mark - Keyboard notifications
- (void)handleWillShowKeyboard:(NSNotification *)notification;
- (void)handleWillHideKeyboard:(NSNotification *)notification;
- (void)keyboardWillShowHide:(NSNotification *)notification;

@end