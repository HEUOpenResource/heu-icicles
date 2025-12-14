<script setup>

import Ohmmeter from './components/OhmmeterDial.vue'
import Table from './components/OhmmeterTable.vue'
import ReadMe from './components/ReadMe.vue';
import { ref } from 'vue'


// 存储从子组件传递过来的 resistances 和 ticks
const resistances = ref([]);
const ticks = ref([]);

// 处理子组件传递的数据
const handleUpdateResistancesAndTicks = (data) => {
  resistances.value = data.resistances;
  ticks.value = data.ticks;
  resistances.value = resistances.value.map(value => parseFloat(value));
  ticks.value = ticks.value.map(value => parseFloat(value));
  resistances.value.push('∞');
  ticks.value.push(0);
};




</script>

<template>
  <ReadMe></ReadMe>

    <Table @updateResistancesAndTicks="handleUpdateResistancesAndTicks"></Table>



  <Ohmmeter :resistances="resistances" :ticks="ticks"></Ohmmeter>

</template>

<style scoped>

</style>
