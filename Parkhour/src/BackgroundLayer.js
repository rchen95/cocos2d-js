var BackgroundLayer = cc.Layer.extend({
    ctor:function () {
        this._super();

        var size = cc.director.getWinSize();
        var centerPos = cc.p(size.width / 2, size.height / 2);
        var spriteBG = cc.Sprite.create(res.s_PlayBG);
        spriteBG.setPosition(centerPos);
        this.addChild(spriteBG);
    }

});

