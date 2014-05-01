var HelloWorldLayer = cc.Layer.extend({
    sprite: null,
    ctor: function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        var size = cc.director.getWinSize();

        var centerPos = cc.p(size.width / 2, size.height / 2);

        var spriteBG = cc.Sprite.create(res.s_HelloBG);  //创建一个精灵，作为背景图
        spriteBG.setPosition(centerPos);                 //位置设置为设计分辨率中心点
        this.addChild(spriteBG);

        cc.MenuItemFont.setFontSize(60);                 //设置菜单字体

        //创建一个精灵菜单项
        var menuItemPlay = cc.MenuItemSprite.create(
            cc.Sprite.create(res.s_start_n),         //normal状态图片
            cc.Sprite.create(res.s_start_s),         //select状态图片
            this.onPlay, this);                      //回调方法以及对应的对象
        var menu = cc.Menu.create(menuItemPlay);     //创建彩蛋
        menu.setPosition(centerPos);
        this.addChild(menu);//添加到layer


        return true;
    },

    // on play button clicked
    onPlay: function (sender) {//sender是发送者实例
        cc.log("==onPlay clicked");
        cc.director.replaceScene(new PlayScene());
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter: function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

