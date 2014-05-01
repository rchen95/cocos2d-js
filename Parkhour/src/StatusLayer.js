var StatusLayer = cc.Layer.extend({
    labelCoin:null,
    labelMeter:null,
    coins:0,

    ctor:function () {
        this._super();

        var winSize = cc.director.getWinSize();
        this.labelCoin = cc.LabelTTF.create("Coins:0", "Helvetica", 20);
        //var labelCoin = cc.LabelTTF.create("Go back", "Arial", 14);
        this.labelCoin.setColor(cc.color(0,0,0));//black color
        this.labelCoin.setPosition(cc.p(70, winSize.height - 20));

        this.addChild(this.labelCoin);


        this.labelMeter = cc.LabelTTF.create("0M", "Helvetica", 20);
        //this.labelMeter.setPosition(cc.p(cc.size.width - 70, cc.size.height - 20));
        this.labelMeter.setPosition(cc.p( winSize.width - 70,  winSize.height  - 20));
        this.addChild(this.labelMeter);
    }
});
