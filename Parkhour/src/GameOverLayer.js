var GameOverLayer = cc.LayerColor.extend({

    // constructor
    ctor:function () {
        this._super(cc.color(0, 0, 0, 180));

        var winSize = cc.director.getWinSize();
        var centerPos = cc.p(winSize.width / 2, winSize.height / 2);

        var restartNormal = cc.Sprite.create(res.s_restart_n);
        var restartSelected = cc.Sprite.create(res.s_restart_s);
        var restartDisabled = cc.Sprite.create(res.s_restart_n);

        cc.MenuItemFont.setFontSize(30);
        var menuItemRestart = cc.MenuItemSprite.create(
            restartNormal,
            restartSelected,
            restartDisabled,
            this.onRestart, this);
        var menu = cc.Menu.create(menuItemRestart);
        menu.setPosition(centerPos);
        this.addChild(menu);
    },



    onRestart:function (sender) {
        var director = cc.director;
        var play = new PlayScene();
        //director.replaceScene(play);
        director.runScene(play);

    }
});
