<template>
  <v-app>
    <v-app-bar app color="#015c44">
      <v-img max-height="50" max-width="150" src="./assets/logo.jpg"></v-img>
      <v-spacer></v-spacer>
      <v-badge
        bordered
        bottom
        color="deep-purple accent-4"
        dot
        offset-x="10"
        offset-y="10"
      >
        <v-avatar size="40">
          <v-img src="https://cdn.vuetifyjs.com/images/lists/2.jpg"></v-img>
        </v-avatar>
      </v-badge>
    </v-app-bar>

    <v-main>
      <HelloWorld />
    </v-main>
    <v-banner outlined shaped>
      <v-icon slot="icon" color="error" size="36"> mdi-alert-outline </v-icon>
      Schiebetüre Tägerwilen defekt
    </v-banner>
  </v-app>
</template>

<script>
import HelloWorld from "./components/HelloWorld";

export default {
  name: "App",

  components: {
    HelloWorld,
  },

  data: () => ({
    //
  }),
};
</script>
