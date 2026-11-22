# Visual Interaction Lab

[العربية](ar.md) · [English](en.md) · [Türkçe](tr.md)

**Local verification; private release candidate**

## Design and implementation

I developed a Windows lab for exploring face and hand analysis in one browser interface. A still image, video file or user-enabled camera supplies frames to a local Python service. YuNet detects faces; one selected face goes to the seven-class EmotiEffLib model through ONNX Runtime. MediaPipe Gesture Recognizer handles the hand path, with a separate experimental landmark rule for OK. The interface distinguishes an unknown gesture from no detected hand.

## Verification, limits and availability

Camera capture starts by user choice and frames are analysed on the same device. The documented private candidate disables real Windows pointer control and retains an in-app preview. Multi-face overlays remain outside the released feature set after the performance check failed; mask assessment lacks independent evaluation data. The candidate passed 48 Python, 18 Node and 17 Chrome automated checks. An earlier KDEF evaluation matched 67 of 71 images from 12 subjects. The uncalibrated scores describe visible expression classes; they cannot establish emotion, general accuracy, real-time performance or recovery after a physical camera interruption. The public page describes the lab; source, model files, weights and training data are private or subject to separate redistribution rights.

[Published case study](https://yahyaalali.com/en/works/visual-interaction-lab/) · [Back to index](../../README.md)
