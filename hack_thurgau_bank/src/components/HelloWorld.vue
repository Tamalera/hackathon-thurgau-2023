<template>
  <v-container>
    <v-row>
      <v-col cols="4">
        <v-card class="full-height" elevation="22">
          <div class="text-h6 font-weight-light mb-2 pl-2">
            Kundenaufkommen Romanshorn
          </div>
          <v-sheet class="v-sheet--offset mx-auto" outlined>
            <v-sparkline
              :labels="labels"
              :value="value"
              color="dark-grey"
              line-width="2"
              padding="16"
            ></v-sparkline>
          </v-sheet>

          <v-card-text class="pt-0">
            <div class="text-center">
              <v-rating v-model="rating">
                <template v-slot:item="props">
                  <v-icon
                    :color="
                      props.isFilled ? genColor(props.index) : 'grey lighten-1'
                    "
                    large
                    @click="props.click"
                  >
                    {{ "mdi-bullhorn" }}
                  </v-icon>
                </template>
              </v-rating>
            </div>
            <v-icon class="mr-2" small> mdi-clock </v-icon>
            <span class="text-caption grey--text font-weight-light"
              >letzter Service vor 14 min</span
            >
          </v-card-text>
        </v-card>
      </v-col>
      <v-col cols="4">
        <v-card class="full-height">
          <div class="text-h6 font-weight-light mb-2 pl-2">
            Kundenaufkommen Frauenfeld
          </div>
          <v-sheet class="v-sheet--offset mx-auto" outlined>
            <v-sparkline
              :labels="labelsF"
              :value="valueF"
              color="dark-grey"
              line-width="2"
              padding="16"
            ></v-sparkline>
          </v-sheet>

          <v-card-text class="pt-0">
            <div class="text-center">
              <v-rating v-model="ratingF">
                <template v-slot:item="props">
                  <v-icon
                    :color="
                      props.isFilled ? genColor(props.index) : 'grey lighten-1'
                    "
                    large
                    @click="props.click"
                  >
                    {{ "mdi-bullhorn" }}
                  </v-icon>
                </template>
              </v-rating>
            </div>
            <v-icon class="mr-2" small> mdi-clock </v-icon>
            <span class="text-caption grey--text font-weight-light"
              >letzter Service vor 3 min</span
            >
          </v-card-text>
        </v-card>
      </v-col>
      <v-col cols="4">
        <v-card class="full-height">
          <div class="text-h6 font-weight-light mb-2 pl-2">
            Kundenaufkommen Weinfelden
          </div>
          <v-sheet class="v-sheet--offset mx-auto" outlined>
            <v-sparkline
              :labels="labelsW"
              :value="valueW"
              color="dark-grey"
              line-width="2"
              padding="16"
            ></v-sparkline>
          </v-sheet>

          <v-card-text class="pt-0">
            <div class="text-center">
              <v-rating v-model="ratingW">
                <template v-slot:item="props">
                  <v-icon
                    :color="
                      props.isFilled ? genColor(props.index) : 'grey lighten-1'
                    "
                    large
                    @click="props.click"
                  >
                    {{ "mdi-bullhorn" }}
                  </v-icon>
                </template>
              </v-rating>
            </div>
            <v-icon class="mr-2" small> mdi-clock </v-icon>
            <span class="text-caption grey--text font-weight-light"
              >letzter Service vor 9 min</span
            >
          </v-card-text>
        </v-card>
      </v-col>
    </v-row>
    <v-row>
      <v-col>
        <div>
          <div class="text-h6 font-weight-light mb-2 pl-2">
            Einsatzplan Romanshorn
          </div>
          <v-sheet height="600">
            <v-calendar
              ref="calendar"
              v-model="valueCal"
              :weekdays="weekday"
              :type="type"
              :events="events"
              :event-overlap-mode="mode"
              :event-overlap-threshold="30"
              :event-color="getEventColor"
              @change="getEvents"
            ></v-calendar>
          </v-sheet>
        </div>
      </v-col>
    </v-row>
  </v-container>
</template>

<script>
export default {
  name: "HelloWorld",

  data: () => ({
    labels: [
      "8:00",
      "9:00",
      "10:00",
      "11:00",
      "12:00",
      "13:00",
      "14:00",
      "15:00",
      "16:00",
      "17:00",
    ],
    value: [2, 14, 12, 18, 29, 44, 32, 23, 5, 8],
    labelsF: [
      "8:00",
      "9:00",
      "10:00",
      "11:00",
      "12:00",
      "13:00",
      "14:00",
      "15:00",
      "16:00",
      "17:00",
    ],
    valueF: [0, 3, 16, 28, 0, 4, 32, 53, 0, 0],
    labelsW: [
      "8:00",
      "9:00",
      "10:00",
      "11:00",
      "12:00",
      "13:00",
      "14:00",
      "15:00",
      "16:00",
      "17:00",
    ],
    valueW: [12, 11, 12, 5, 9, 13, 15, 23, 0, 2],
    colors: ["green", "light-green", "yellow", "orange", "red"],
    rating: 2.5,
    ratingF: 4.5,
    ratingW: 3.0,

    // Calendar
    weekday: [0, 1, 2, 3, 4, 5, 6],
    weekdays: [
      { text: "SO - SA", value: [0, 1, 2, 3, 4, 5, 6] },
      { text: "MO - SO", value: [1, 2, 3, 4, 5, 6, 0] },
      { text: "MO - FR", value: [1, 2, 3, 4, 5] },
      { text: "MO, MI, FR", value: [1, 3, 5] },
    ],
    valueCal: "",
    events: [],
    colorsCal: [
      "blue",
      "indigo",
      "deep-purple",
      "cyan",
      "green",
      "orange",
      "grey darken-1",
    ],
    names: [
      "Sophia",
      "Robert",
      "Tim",
      "Lukas",
      "Sergio",
      "Brian",
      "Olivia",
      "Fabia",
    ],
  }),
  methods: {
    genColor(i) {
      return this.colors[i];
    },
    getEvents({ start, end }) {
      const events = [];

      const min = new Date(`${start.date}T00:00:00`);
      const max = new Date(`${end.date}T23:59:59`);
      const days = (max.getTime() - min.getTime()) / 86400000;
      const eventCount = this.rnd(days, days + 20);

      for (let i = 0; i < eventCount; i++) {
        const allDay = this.rnd(0, 3) === 0;
        const firstTimestamp = this.rnd(min.getTime(), max.getTime());
        const first = new Date(firstTimestamp - (firstTimestamp % 900000));
        const secondTimestamp = this.rnd(2, allDay ? 288 : 8) * 900000;
        const second = new Date(first.getTime() + secondTimestamp);

        events.push({
          name: this.names[this.rnd(0, this.names.length - 1)],
          start: first,
          end: second,
          colorsCal: this.colorsCal[this.rnd(0, this.colorsCal.length - 1)],
          timed: !allDay,
        });
      }

      this.events = events;
    },
    getEventColor(event) {
      return event.colorsCal;
    },
    rnd(a, b) {
      return Math.floor((b - a + 1) * Math.random()) + a;
    },
  },
};
</script>
