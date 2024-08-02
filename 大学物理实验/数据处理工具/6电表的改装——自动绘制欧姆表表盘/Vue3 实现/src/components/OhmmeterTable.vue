<template>
    <div class="flex row center">
        <!-- 第一部分表格 -->
        <el-table :data="firstHalfTableData" border style="width: 300px" class="m2">
            <el-table-column prop="resistances" label="Rx/欧" width="150">
                <template #default="scope">
                    <el-input v-model="scope.row.resistances" placeholder="输入电阻值" size="small"  />
                </template>
            </el-table-column>
            <el-table-column prop="ticks" label="刻度" width="150">
                <template #default="scope">
                    <el-input v-model="scope.row.ticks" placeholder="输入刻度值" size="small"  />
                </template>
            </el-table-column>
        </el-table>

        <!-- 第二部分表格 -->
        <el-table :data="secondHalfTableData" border style="width: 300px" class="m2">
            <el-table-column prop="resistances" label="Rx/欧" width="150">
                <template #default="scope">
                    <el-input v-model="scope.row.resistances" placeholder="输入电阻值" size="small"  />
                </template>
            </el-table-column>
            <el-table-column prop="ticks" label="刻度" width="150">
                <template #default="scope">
                    <el-input v-model="scope.row.ticks" placeholder="输入刻度值" size="small"  />
                </template>
            </el-table-column>
        </el-table>
    </div>
</template>

<script setup>
import { ref, watch } from 'vue';

// 原始数据
const tableData = ref([
    { resistances: '0', ticks: '25.0' },
    { resistances: '10', ticks: '23.0' },
    { resistances: '20', ticks: '21.2' },
    { resistances: '30', ticks: '19.7' },
    { resistances: '60', ticks: '16.1' },
    { resistances: '90', ticks: '13.8' },
    { resistances: '120', ticks: '12.0' },
    { resistances: '280', ticks: '7.0' },
    { resistances: '360', ticks: '5.9' },
    { resistances: '480', ticks: '4.9' },
    { resistances: '600', ticks: '4.0' },
    { resistances: '1000', ticks: '2.6' },
    { resistances: '2000', ticks: '1.4' },
    { resistances: '3000', ticks: '1.0' },
]);

// 将数据拆分为两部分
const firstHalfTableData = ref(tableData.value.slice(0, Math.ceil(tableData.value.length / 2)));
const secondHalfTableData = ref(tableData.value.slice(Math.ceil(tableData.value.length / 2)));

// 存储 resistances 和 ticks 的列表
const resistancesList = ref([]);
const ticksList = ref([]);

// 使用 defineEmits 定义事件
const emit = defineEmits(['updateResistancesAndTicks']);

// 监听 tableData 的变化，将 resistances 和 ticks 存储到列表中，并传递给父组件
watch(tableData, (newTableData) => {
    resistancesList.value = newTableData.map(item => item.resistances);
    ticksList.value = newTableData.map(item => item.ticks);

    // 触发事件，将列表传递给父组件
    emit('updateResistancesAndTicks', { resistances: resistancesList.value, ticks: ticksList.value });
}, { deep: true });
</script>

<style scoped>
.flex {
    display: flex;
}

.row {
    flex-direction: row;
}
.center {
    justify-content: center;
    align-items: center;
}
.m2{
    margin: 2px;

}

@media (max-width: 650px) {
    .row {
        flex-direction: column;
    }

}
</style>
