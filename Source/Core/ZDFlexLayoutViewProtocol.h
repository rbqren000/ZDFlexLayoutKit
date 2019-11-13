//
//  ZDFlexLayoutViewProtocol.h
//  Demo
//
//  Created by Zero.D.Saber on 2019/10/11.
//  Copyright © 2019 Zero.D.Saber. All rights reserved.
//

#ifndef ZDFlexLayoutViewProtocol_h
#define ZDFlexLayoutViewProtocol_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZDFlexLayoutViewProtocol;
typedef id<ZDFlexLayoutViewProtocol> ZDFlexLayoutView;

@class ZDFlexLayout;
@protocol ZDFlexLayoutViewProtocol <NSObject>

@property (nonatomic, assign, readonly) BOOL isFlexLayoutEnabled;
@property (nonatomic, strong, readonly) ZDFlexLayout *flexLayout;
@property (nonatomic, weak, nullable) ZDFlexLayoutView parent;
@property (nonatomic, weak, nullable) UIView *owningView;  ///< 持有自己的视图
@property (nonatomic, strong) NSMutableArray<ZDFlexLayoutView> *children;
@property (nonatomic, assign) CGRect layoutFrame;

- (void)addChild:(ZDFlexLayoutView)child;
- (void)removeChild:(ZDFlexLayoutView)child;

- (void)addChildren:(NSArray<ZDFlexLayoutView> *)children;
- (void)removeChildren:(NSArray<ZDFlexLayoutView> *)children;

- (CGSize)sizeThatFits:(CGSize)size;

- (void)configureFlexLayoutWithBlock:(void(NS_NOESCAPE ^)(ZDFlexLayout *layout))block;

@optional
- (void)needReApplyLayoutAtNextRunloop;

@end

NS_ASSUME_NONNULL_END

#endif /* ZDFlexLayoutViewProtocol_h */
