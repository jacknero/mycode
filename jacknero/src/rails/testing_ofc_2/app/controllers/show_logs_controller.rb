class ShowLogsController < ApplicationController
  def index
    respond_to do |wants|
      wants.html {
        @graph = open_flash_chart_object( 300, 300, url_for( :action => :index, :format => :json ,:post => params[:post]) )
      }
      wants.json {
        year = params[:post]["written_on(1i)"]
        month =  params[:post]["written_on(2i)"]
        day =  params[:post]["written_on(3i)"]

        start_date = Date::new(year.to_i,month.to_i,day.to_i)

        weeks=[]
        7.times do |i|
          weeks <<  start_date.advance(:days => i)
        end


        chart = OpenFlashChart.new( "weeks log " ) do |c|
          #c << BarGlass.new( :values => (1..10).sort_by{rand} )
          c << BarGlass.new( :values => [1,2,3,4,5,6,7,8,9,10] )
        end
        render :text => chart, :layout => false
      }

    end
  end
end
