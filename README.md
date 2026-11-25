# camera123 — UE5 Camera Refinement

作者：**南京大学24届沈逸文** · 当前版本：**0.2.1**

为 UE5 相机提供近裁剪平面像素世界位置，让官方 PostProcessVolume 的硬边界可以在同一画面内按像素分区。无需给背景物体换材质，也无需在关卡放置插件控制 Actor。

## 使用前说明

- **坐标定义**：像素中心在相机近裁剪平面上的世界位置，不是可见物体表面位置。不读取场景深度来反推该位置。
- **支持基准**：Windows x64、UE **5.7.4**、D3D12 / SM5。其他 UE 版本需重新编译；XR、移动端、路径追踪等不在当前已适配范围。
- **硬边界与软边界不同**：官方体积硬边界按真实凸包选择原生渲染配置；软边界采用完整原生画面输出插值，不能视为所有原生参数的逐像素精确混合。
- **存在明显渲染成本**：同时跨越 1 / 2 / 3 个体积时，最坏额外渲染 **1 / 3 / 7 次完整场景**，另加一次合成。默认最多 8 个配置。该方案不是低成本的全局 CameraPositionWS 替换。
- **自定义材质仍需接入**：使用 MF_RefinedCameraPosition 替换需要细化的相机位置输入。插件不会改写引擎所有 CameraPositionWS 读取。
- **时间相关效果需评估**：自动曝光历史、TAA/TSR、景深和跨区域模糊可能与多配置合成存在差异。超过预算或遇到未适配接口时，插件报告“原生回退”并保留引擎默认输出。

本仓库只发布整理后的 **UE5 插件**，不包含 Godot 工程、测试工程、测试代码、演示场景、日志或 AI 桥接插件。插件仍标记为 Beta，请按目标工程画质和性能预算评估。

## 下载与安装

推荐下载 [v0.2.1 完整安装包](https://github.com/mingtu149411/camera123/releases/download/v0.2.1/CameraRefinement_UE5.7_Win64_v0.2.1.zip)。也可使用仓库内的 [同版本安装包](dist/CameraRefinement_UE5.7_Win64_v0.2.1.zip)。

1. 关闭目标工程的 UE 编辑器。
2. 解压，将完整的 CameraRefinement 文件夹复制到 `<工程>/Plugins/`，确认存在 `<工程>/Plugins/CameraRefinement/CameraRefinement.uplugin`。
3. 打开工程，在“编辑 → 插件”启用 Camera Refinement 并重启。
4. 在顶部播放工具栏开启“默认相机细化”，或在 CameraActor / CameraComponent 详情中开启“细化”。

如果直接克隆仓库，安装目录是 `Plugins/CameraRefinement`，不要把整个 camera123 仓库目录当成插件。请完整保留插件中的 Intermediate：其中包含 UAT 发行所需的 Development/Shipping 预编译对象和清单。

## 开关与官方体积

默认相机无需出现在 Outliner 中，使用顶部“默认相机细化”即可。优先级为：**相机显式设置 > 外部默认开关 > 初始关闭**。相机详情中的“跟随默认”移除本地覆盖。

已有官方 PostProcessVolume 自动读取。观察硬边界时，启用体积、关闭 Unbound、令 BlendWeight>0、BlendRadius=0，并设置可见的白平衡或颜色覆盖。以斜角使近裁剪平面同时跨越体积两侧。若边界与近裁剪面平行，整屏一起切换可能正是正确结果。

## 文档

- [安装与使用说明](Plugins/CameraRefinement/Documentation/安装与使用说明.md)
- [技术说明：坐标、原生参数栈、凸包分类、合成与回退](Plugins/CameraRefinement/Documentation/技术说明.md)
- [作者标识与文件完整性](Plugins/CameraRefinement/Documentation/作者标识与文件完整性.md)

## 目录

```text
Plugins/CameraRefinement/   完整插件、源码、着色器、材质函数和文档
dist/                      完整安装包
AUTHORSHIP.json            仓库文件作者与 SHA-256 清单
Apply-AuthorMetadata.ps1    可选的 NTFS 作者元数据恢复脚本
```

作者标识不会绘制到游戏画面，也不参与渲染算法。Git 不保存 NTFS 备用数据流；克隆或解压后可运行 Apply-AuthorMetadata.ps1 恢复。源码署名、插件/资产元数据、二进制署名字符串和 SHA-256 清单仍随文件保留。署名和校验不属于数字签名。
