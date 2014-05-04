// define enum for runner status
if(typeof RunnerStat == "undefined") {
    var RunnerStat = {};
    RunnerStat.running = 0;
    RunnerStat.jumpUp = 1;
    RunnerStat.jumpDown = 2;
};


var spriteFrameCache = cc.spriteFrameCache;

var AnimationLayer = cc.Layer.extend({
    spriteSheet:null,
    runningAction:null,
    sprite:null,

    space:null,
    body:null,
    shape:null,

    jumpUpAction:null,
    jumpDownAction:null,

    recognizer:null,
    stat:RunnerStat.running,// init with running status


    ctor:function (space) {
        this._super();


        this.space = space;

        // create sprite sheet
        cc.spriteFrameCache.addSpriteFrames(res.s_runnerplist);
        this.spriteSheet = cc.SpriteBatchNode.create(res.s_runner);
        this.addChild(this.spriteSheet);

        // init runningAction
        this.initAction();

        this.sprite = cc.PhysicsSprite.create("#runner0.png");
        var contentSize = this.sprite.getContentSize();

        // init body
        this.body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));  // init the runner physic body
        this.body.p = cc.p(g_runnerStartX, g_groundHight + contentSize.height / 2);             // set the position of the runner
        this.body.applyImpulse(cp.v(150, 0), cp.v(0, 0));                                       // run speed, apply impulse to the body
        this.space.addBody(this.body);
        //init shape
        this.shape = new cp.BoxShape(this.body, contentSize.width - 14, contentSize.height);
        this.space.addShape(this.shape);

        this.sprite.setBody(this.body);
        this.sprite.runAction(this.runningAction);
        this.spriteSheet.addChild(this.sprite);

        this.recognizer = new SimpleRecognizer();
        // enable touch
        //this.setTouchEnabled(true);
        // set touch mode to kCCTouchesOneByOne
        //this.setTouchMode(1);

        cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: this.onTouchBegan,
            onTouchMoved: this.onTouchMoved,
            onTouchEnded: this.onTouchEnded
        }, this);

        //Schedules the "update" method
        this.scheduleUpdate();

    },
    getEyeX:function () {
        return this.sprite.getPositionX() - g_runnerStartX;
    },

    update:function (dt) {
        // update meter
        var statusLayer = this.getParent().getChildByTag(TagOfLayer.Status);
        statusLayer.updateMeter(this.sprite.getPositionX() - g_runnerStartX);

        var eyeX = this.sprite.getPositionX() - g_runnerStartX;
        var camera = this.getCamera();
        var eyeZ = cc.Camera.getZEye();
        camera.setEye(eyeX, 0, eyeZ);
        camera.setCenter(eyeX, 0, 0);
    },

    onExit:function() {
        this.runningAction.release();
        this.jumpUpAction.release();
        this.jumpDownAction.release();

        spriteFrameCache.removeSpriteFramesFromFile(res.s_runnerplist);

        this._super();
    },

    initAction:function () {
        // init runningAction
        var animFrames = [];
        // num equal to spriteSheet
        for (var i = 0; i < 8; i++) {
            var str = "runner" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        var animation = cc.Animation.create(animFrames, 0.1);
        this.runningAction = cc.RepeatForever.create(cc.Animate.create(animation));
        this.runningAction.retain();

        // init jumpUpAction
        animFrames = [];
        for (var i = 0; i < 4; i++) {
            var str = "runnerJumpUp" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        animation = cc.Animation.create(animFrames, 0.2);
        this.jumpUpAction = cc.Animate.create(animation);
        this.jumpUpAction.retain();

        // init jumpDownAction
        animFrames = [];
        for (var i = 0; i < 2; i++) {
            var str = "runnerJumpDown" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        animation = cc.Animation.create(animFrames, 0.3);
        this.jumpDownAction = cc.Animate.create(animation);
        this.jumpDownAction.retain();
    },

    onTouchBegan:function(touch, event) {
        var pos = touch.getLocation();
        event.getCurrentTarget().recognizer.beginPoint(pos.x, pos.y);
        //this.recognizer.beginPoint(pos.x, pos.y);
        return true;
    },

    onTouchMoved:function(touch, event) {
        var pos = touch.getLocation();
        //this.recognizer.movePoint(pos.x, pos.y);
        event.getCurrentTarget().recognizer.movePoint(pos.x, pos.y);
    },

    onTouchEnded:function(touch, event) {
        //var rtn = this.recognizer.endPoint();
        var rtn = event.getCurrentTarget().recognizer.endPoint();

        switch (rtn) {
            case "up":
                event.getCurrentTarget().jump();
                break;
            default:
                break;
        }
    },

    jump:function () {
        if (this.stat == RunnerStat.running) {
            this.body.applyImpulse(cp.v(0, 250), cp.v(0, 0));
            this.stat = RunnerStat.jumpUp;
            this.sprite.stopAllActions();
            this.sprite.runAction(this.jumpUpAction);

            audioEngine.playEffect(res.s_music_jump);
        }
    }

});

AnimationLayer.prototype.setupDebugNode = function(enable)
{
    // debug only
    this._debugNode = cc.PhysicsDebugNode.create( this.space );
    this._debugNode.visible = enable ;
    this.addChild( this._debugNode );
};