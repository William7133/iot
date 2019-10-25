import { Component } from '@angular/core';


@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'pokemon';

  getData() {
      this.http.get('https://api.fakeservice.com/datas').subscribe(res => {
          console.log(res)
      });
  }
}
