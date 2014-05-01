var StatusLayer = cc.Layer.extend({
    labelCoin:null,
    labelMeter:null,
    coins:0,

    ctor:function () {
        this._super();

        this.labelCoin = cc.LabelTTF.create("Coins:0", "Helvetica", 20);
        this.labelCoin.setColor(cc.c3(0,0,0));//black color
        this.labelCoin.setPosition(cc.p(70, cc.size.height - 20));
        this.addChild(this.labelCoin);

        this.labelMeter = cc.LabelTTF.create("0M", "Helvetica", 20);
        this.labelMeter.setPosition(cc.p(cc.size.width - 70, cc.size.height - 20));
        this.addChild(this.labelMeter);
    }
});
