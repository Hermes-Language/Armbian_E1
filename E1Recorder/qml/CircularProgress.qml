import QtQuick
import QtQuick.Controls

Item {
    id: circularProgress
    width: 120
    height: 120
    
    property real value: 0.0  // 0.0 to 1.0
    property real strokeWidth: 8
    property color progressColor: "#9c27b0"  // Material Purple
    property color backgroundColor: "#424242"
    
    Canvas {
        id: canvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            var centerX = width / 2;
            var centerY = height / 2;
            var radius = (Math.min(width, height) / 2) - strokeWidth;
            
            ctx.reset();
            
            // 背景圆环
            ctx.beginPath();
            ctx.lineWidth = strokeWidth;
            ctx.strokeStyle = backgroundColor;
            ctx.arc(centerX, centerY, radius, 0, Math.PI * 2);
            ctx.stroke();
            
            // 进度弧
            if (value > 0) {
                ctx.beginPath();
                ctx.lineWidth = strokeWidth;
                ctx.strokeStyle = progressColor;
                ctx.lineCap = "round";
                var startAngle = -Math.PI / 2; // 从顶部开始
                var endAngle = startAngle + (Math.PI * 2 * value);
                ctx.arc(centerX, centerY, radius, startAngle, endAngle);
                ctx.stroke();
            }
        }
    }
    
    // 中心文本显示百分比
    Label {
        anchors.centerIn: parent
        text: Math.round(value * 100) + "%"
        font.pixelSize: 16
        font.weight: Font.Bold
        color: "#ffffff"
    }
    
    onValueChanged: canvas.requestPaint()
} 