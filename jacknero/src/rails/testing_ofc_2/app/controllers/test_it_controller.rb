class TestItController < ApplicationController
  def index
    respond_to do |wants|
      wants.html {
        @graph = open_flash_chart_object( 300, 300, url_for( :action => :index, :format => :json ) )
        @graph1 = open_flash_chart_object( 600, 300, url_for( :action => :graph1, :format => :json ) )
      }
      wants.json { 
        chart = OpenFlashChart.new( "weeks log " ) do |c|
        c << BarGlass.new( :values => (1..10).sort_by{rand} )
        end
      render :text => chart, :layout => false
      }
    end
  end

  def graph1
    respond_to do |wants|
      wants.html {
        @graph = open_flash_chart_object( 600, 300, url_for( :action => :graph1, :format => :json ) )
      }
      wants.json { 
        title = Title.new("logs")

        data1 = []
        data2 = []
        data3 = []

        10.times do |x|
          data1 << rand(5) + 1
          data2 << rand(6) + 7
          data3 << rand(5) + 14
        end

        line_dot = LineDot.new
        line_dot.text= "login"
        line_dot.width = 4
        #line_dot.colour = '#DFC329'
        line_dot.colour = '#000000'
        line_dot.dot_size = 2
        line_dot.values = data1

        line_hollow = LineHollow.new
        line_hollow.text = "Logout"
        line_hollow.width = 1
        line_hollow.colour = '#6363AC'
        line_hollow.dot_size = 5
        line_hollow.values = data2

        line = Line.new
        line.text = "go away"
        line.width = 1
        line.colour = '#5E4725'
        line.dot_size = 5
        line.values = data3

        # Added these lines since the previous tutorial
        tmp = []
        x_labels = XAxisLabels.new
        x_labels.set_vertical()


                                                                                                          %w(18 19 20 21 22 23 24 25 26  27).each do |text|
                                                                                                            tmp << XAxisLabel.new(text, '#0000ff', 20, 'diagonal')
                                                                                                          end

                                                                                                          x_labels.labels = tmp

                                                                                                          x = XAxis.new
                                                                                                          x.set_labels(x_labels)
                                                                                                          # new up to here ...

                                                                                                          y = YAxis.new
                                                                                                          y.set_range(0,20,5)

                                                                                                          x_legend = XLegend.new("date ")
                                                                                                          x_legend.set_style('{font-size: 20px; color: #778877}')

                                                                                                          y_legend = YLegend.new("access")
                                                                                                          y_legend.set_style('{font-size: 20px; color: #770077}')

                                                                                                          chart =OpenFlashChart.new
                                                                                                          chart.set_title(title)
                                                                                                          chart.set_x_legend(x_legend)
                                                                                                          chart.set_y_legend(y_legend)
                                                                                                          chart.x_axis = x # Added this line since the previous tutorial
                                                                                                          chart.y_axis = y

                                                                                                          chart.add_element(line_dot)
                                                                                                          chart.add_element(line_hollow)
                                                                                                          chart.add_element(line)

                                                                                                          render :text => chart, :layout => false
      }
    end
  end

  def graph2
    respond_to do |wants|
      wants.html {
        @graph = open_flash_chart_object( 600, 300, url_for( :action => :graph2, :format => :json ) )
      }
      wants.json { 
        # based on this example - http://teethgrinder.cookies.uk/open-flash-chart-2/pie-chart.php
        title = Title.new("Number of logins")

        pie = Pie.new
        pie.start_angle = -90
        pie.animate = false
        pie.tooltip = '#val# of #total#<br>#percent# of 100%'
        pie.colours = ["#d01f3c", "#356aa0", "#C79810"]
        pie.values  = [2,PieValue.new(10,"docomo"), PieValue.new(26,"PC ")]

        chart = OpenFlashChart.new
        chart.title = title
        chart.add_element(pie)

        chart.x_axis = nil

        #render :text => chart.to_s

        render :text => chart, :layout => false
      }
    end
  end
end
