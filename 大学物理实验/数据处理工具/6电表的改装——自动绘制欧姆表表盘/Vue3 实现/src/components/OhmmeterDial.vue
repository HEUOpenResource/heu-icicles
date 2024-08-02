<template>
    <div class="ohmmeter-dial">
        <canvas ref="dialCanvas" :width="canvasWidth" :height="canvasHeight"></canvas>
    </div>
</template>

<script setup>
import { ref, onMounted, onBeforeUnmount, watchEffect } from 'vue';

const props = defineProps({
    resistances: {
        type: Array,
        required: true,
    },
    ticks: {
        type: Array,
        required: true,
    },
});

const canvasWidth = ref(1000);
const canvasHeight = ref(1000);
const dialCanvas = ref(null);

const isMobile = ref(false);

const updateCanvasSize = () => {
    if (window.innerWidth < 700) {
        canvasWidth.value = 400;
        canvasHeight.value = 500;
        isMobile.value = true; // 手机端
    } else {
        canvasWidth.value = 700;
        canvasHeight.value = 700;
        isMobile.value = false; // 桌面端
    }
};

const drawDial = () => {
    const canvas = dialCanvas.value;
    if (!canvas) return;

    const ctx = canvas.getContext("2d");
    ctx.clearRect(0, 0, canvasWidth.value, canvasHeight.value);

    const centerX = canvasWidth.value / 2;
    const centerY = canvasHeight.value / 2;
    const radius = Math.min(centerX, centerY) * 0.9;

    const angles = props.ticks.map(tick => (tick / 25) * (2 / 3) * Math.PI - (Math.PI * 5 / 6));

    angles.forEach((angle, index) => {
        const resistance = props.resistances[index];
        const startX = centerX + radius * Math.cos(angle);
        const startY = centerY + radius * Math.sin(angle);
        const endX = centerX + (radius - 30) * Math.cos(angle);
        const endY = centerY + (radius - 30) * Math.sin(angle);

        ctx.beginPath();
        ctx.moveTo(startX, startY);
        ctx.lineTo(endX, endY);
        ctx.strokeStyle = "red";
        ctx.lineWidth = 2;
        ctx.stroke();

        const labelX = centerX + (isMobile.value ? radius + 30 : radius - 40) * Math.cos(angle);
        const labelY = centerY + (isMobile.value ? radius + 30 : radius - 40) * Math.sin(angle);
        ctx.font = "12px Arial";
        ctx.fillStyle = "black";
        ctx.textAlign = angle < -Math.PI / 3 ? "left" : angle > -2 * Math.PI / 3 ? "right" : "center";
        ctx.fillText(`${resistance}Ω`, labelX, labelY);
    });

    for (let i = 0; i <= 100; i++) {
        const angle = (i / 100) * (2 / 3) * Math.PI - (Math.PI * 5 / 6);
        const startX = centerX + radius * Math.cos(angle);
        const startY = centerY + radius * Math.sin(angle);
        const endX = centerX + (radius - (i % 10 === 0 ? 15 : 10)) * Math.cos(angle);
        const endY = centerY + (radius - (i % 10 === 0 ? 15 : 10)) * Math.sin(angle);

        ctx.beginPath();
        ctx.moveTo(startX, startY);
        ctx.lineTo(endX, endY);
        ctx.strokeStyle = "gray";
        ctx.lineWidth = 1;
        ctx.stroke();

        if (i % 10 === 0) {
            const labelX = centerX + (radius - 25) * Math.cos(angle);
            const labelY = centerY + (radius - 25) * Math.sin(angle);
            ctx.font = "10px Arial";
            ctx.fillStyle = "gray";
            ctx.textAlign = "center";
            ctx.fillText(`${i}uA`, labelX, labelY);

            if (i === 50) {
                ctx.font = "14px Arial";
                ctx.fillText("R中", labelX, labelY - 15);
            }
        }
    }
};

onMounted(() => {
    updateCanvasSize();
    drawDial();
    window.addEventListener('resize', updateCanvasSize);
    window.addEventListener('resize', drawDial);
});

onBeforeUnmount(() => {
    window.removeEventListener('resize', updateCanvasSize);
    window.removeEventListener('resize', drawDial);
});

watchEffect(() => {
    drawDial();
});
</script>

<style scoped>
.ohmmeter-dial {
    display: flex;
    justify-content: center;
    align-items: center;
    margin-top: 20px;
}
</style>
