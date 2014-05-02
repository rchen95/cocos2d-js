var AnimationLayer = cc.Layer.extend({
    spriteSheet:null,
    runningAction:null,
    sprite:null,

    ctor:function () {
        this._super();

        // create sprite sheet
        cc.spriteFrameCache.addSpriteFrames(res.s_runnerplist);
        this.spriteSheet = cc.SpriteBatchNode.create(res.s_runner);
        this.addChild(this.spriteSheet);

        // init runningAction
        var animFrames = [];
        for (var i = 0; i < 8; i++) {
            var str = "runner" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        var animation = cc.Animation.create(animFrames, 0.1);
        this.runningAction = cc.RepeatForever.create(cc.Animate.create(animation));

        this.sprite = cc.Sprite.create("#runner0.png");
        this.sprite.setPosition(cc.p(80, 85));
        this.sprite.runAction(this.runningAction);
        this.spriteSheet.addChild(this.sprite);

    }
});