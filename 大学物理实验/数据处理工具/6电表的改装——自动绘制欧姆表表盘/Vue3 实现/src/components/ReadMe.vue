
<template>
    <div class='paper '>

        <h2 class="text-center">电表的改装——自动绘制欧姆表表头</h2>
        <blockquote>
            <el-tag type="primary">网页介绍</el-tag>
            <hr />
            <p>这是电表的改装——绘制欧姆表头的网页，大家只需要把表格的数据替换成自己的即可自动绘制。</p>
            <el-tag type="success">使用说明</el-tag>
            <hr />
            <p>填写表格修改自己实验时测得的刻度，表盘就会实时更新。</p>
            <p>将最后的网页效果另存为 PDF 然后打印出来即就可以啦。</p>
            <el-tag type="warning">代码完善</el-tag>
            <hr />
            <p>代码已上传到 <el-link type="primary"
                    href="https://github.com/HEUOpenResource/heu-icicles">哈尔滨工程大学课程攻略共享计划</el-link>，欢迎完善与更新！</p>
        </blockquote>
    </div>
</template>

<style scoped>
.el-link {
    margin-right: 8px;
}

.el-link .el-icon--right.el-icon {
    vertical-align: text-bottom;
}

.text-center {
  text-align: center;
}

  .paper {
      width: 600px;
      position: relative;
      margin: 30px auto;
      padding: 30px 0;
      border: 1px solid #efefef;
      background-color: #FFFFFD;
      /* background-image: url(paper.png); */
      box-shadow: 0 1px 4px rgba(0, 0, 0, 0.27), 0 0 40px rgba(0, 0, 0, 0.06) inset;

      &::before,
      &::after {
          content: '';
          z-index: -1;
          position: absolute;
          left: 10px;
          bottom: 10px;
          width: 45%;
          height: 55%;
          max-height: 100px;
          box-shadow: 0 8px 16px rgba(0, 0, 0, 0.3);
          transform: skew(-15deg) rotate(-4deg);
      }

      &::after {
          left: auto;
          right: 10px;
          transform: skew(15deg) rotate(4deg);
      }
  }
@media (max-width: 650px) {
    .paper {
        width: 100%;
        padding: 10px 0;
    }

}
</style>