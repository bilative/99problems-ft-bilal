I'll host my own personal website soon. And I'm on [x-days-of-code](https://bilative.github.io/xdaysofcode) challange. I decided to build activity heatmap (like github commit heatmap) and I searched little bit. And found the way that I can create it, but the problem was automizing.

Firstly, I'm keeping my daily notes on database, everyday I add new notes with edditional information. They are like this: 
![image](https://user-images.githubusercontent.com/70684994/134415460-a1b1cd8e-ec67-434e-9efe-b0e55364f14a.png)

- Header and date values are for adding to html as h3 and h4 tags.
- Activity column shows if I coded or it was day off. 
- date_log is representative date column for me to sort operations,
- and post is the main post that I share with the followers.

Now, problem is clear. For heatmap presentation I needed this informations:
- For everyday/ date, 1 and 0 values,
  - (Actually as you can see Day_44-45 I dont fill the summaries daily. So there are no individual 1 and 0 values for everyday.)
  - But I know that I inserted 0 when I didnt code.
- Weekday information for everydate for y-axis of the visual.
  - first day is monday,
  - 5th day is friday
  - and 7th day is sunday as you know
    - (I ranked them 0 to 6)
- And cumulative sums of active days weekly.
  - Actually I said weekly but I should took starting point of the week as monday.
     - My journey was started at friday, so every monday is the 3 + ( 6 * n ), n= 1, 2, 3 ... infinity

And I shouldn't generate this with every refresh, bc we know this chart wont change everyday. So I can use Apache Airflow to build this chart at 8 oclock everyday.

### Here I generated the dates between now and my starting day.
```python
# here is a mistake
# I should insert dates as yyyy-mm-dd but I took them as dd.mm.yyyy, little fixing here
def fix_dates(date_list):
    return pd.to_datetime([i[6:10]+'-'+i[3:5]+'-'+i[:2] for i in date_list])
true_date = fix_dates(dfs['date_log'])

start_date = true_date.min()
end_date   = true_date.max()

delta = end_date - start_date

dates_between = [start_date + datetime.timedelta(i) for i in range(delta.days+1)]
activity_dataframe = pd.DataFrame({
    'dates' : dates_between,
    'activity' : 1 # this value is dummy for now
})
```

### And here the my activity situations day by day
```python
# days that I wasn't coded
day_offs = list(dfs[dfs['activity'] == 0]['date_log'])

real_activities = []
for i in activity_dataframe['dates'].astype(str):
    if str(i) in fix_dates(day_offs):
        real_activities.append(0)
    else:
        real_activities.append(1)
activity_dataframe['real_activities'] = real_activities
```

### Here is the weekdays
```python
activity_dataframe['weekday'] = pd.to_datetime(activity_dataframe['dates']).apply(lambda x: x.weekday())
```

### Here is the cumulative summation.
```python
week_th = 3 # third day of my process, week refreshed
cumsum_ = []
for i in range(len(activity_dataframe)):
    if i < week_th:
        cumsum_.append(activity_dataframe['real_activities'][:week_th].sum())
    else:
        week_th+=7
        cumsum_.append(activity_dataframe['real_activities'][:week_th].sum())

activity_dataframe['cumsum_'] = cumsum_

activity_dataframe['cumsum_'] = activity_dataframe['cumsum_'].apply(lambda x: '_'+str(x)+'_') # plotly see str(values) as integer, I should make plotly focused
```

This one is the codes of graph ([this post](https://community.plotly.com/t/colored-calendar-heatmap-in-dash/10907/2) gave most part of the plot actually):
```python
def commit_heatmap(df):
    colorscale = [[False, "#eeeeee"], [True, "#70cf60"]]
    data = [
        go.Heatmap(
            x=df['cumsum_'],
            y=df['weekday'],
            z=df['real_activities'],
            text=df['dates'],
            hoverinfo="text",
            xgap=3,
            ygap=3,
            showscale=False,
            colorscale=colorscale
        )
    ]
    layout = go.Layout(
        height=230,
        yaxis=dict(
            ticktext=["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"],
            tickvals=[0, 1, 2, 3, 4, 5, 6],
        ),
        width=270,
        font={"size": 10, "color": "#aeaeae"},
        plot_bgcolor=("#fff"),
        margin=dict(t=40, b=30, r=20, l=20),
    )
    fig = go.Figure(data=data, layout=layout)
    fig.update_xaxes(side="top")
    return fig

commit_heatmap(activity_dataframe)
```
![newplot](https://user-images.githubusercontent.com/70684994/134423133-a02dbe88-713f-4564-bc6c-f658345b59f5.png)

