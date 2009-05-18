class PostsController < ApplicationController  
  
  # GET /posts
  # GET /posts.xml
  def index
    @posts = Post.find(:all)

    respond_to do |format|
      format.html # index.html.erb
      format.xml  { render :xml => @posts }
    end
  end

  # GET /posts/1
  # GET /posts/1.xml
  def show
    @post = Post.find(params[:id])
    @post_comments = @post.comments.collect    
    flash[:post_id] = @post.id
    respond_to do |format|
      format.html # show.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/new
  # GET /posts/new.xml
  def new
    @post = Post.new

    respond_to do |format|
      format.html # new.html.erb
      format.xml  { render :xml => @post }
    end
  end

  # GET /posts/1/edit
  def edit
    @post = Post.find(params[:id])
  end

  # POST /posts
  # POST /posts.xml
  def create
    @post = Post.new(params[:post])

    respond_to do |format|
      if @post.save
        flash[:notice] = 'Post was successfully created.'
        format.html { redirect_to(@post) }
        format.xml  { render :xml => @post, :status => :created, :location => @post }
      else
        format.html { render :action => "new" }
        format.xml  { render :xml => @post.errors, :status => :unprocessable_entity }
      end
    end
  end

  # PUT /posts/1
  # PUT /posts/1.xml
  def update
    @post = Post.find(params[:id])

    respond_to do |format|
      if @post.update_attributes(params[:post])
        flash[:notice] = 'Post was successfully updated.'
        format.html { redirect_to(@post) }
        format.xml  { head :ok }
      else
        format.html { render :action => "edit" }
        format.xml  { render :xml => @post.errors, :status => :unprocessable_entity }
      end
    end
  end

  # DELETE /posts/1
  # DELETE /posts/1.xml
  def destroy
    @post = Post.find(params[:id])
    @post.destroy

    respond_to do |format|
      format.html { redirect_to(posts_url) }
      format.xml  { head :ok }
    end
  end
  
  def post_comment
    @comment = Comment.new(
      "post_id" => flash[:post_id],
      "created_at" => Time.now,
      "comment" => params[:comment]['comment']
    )
    if @comment.save
      flash[:notice] = 'Comment was successfully added.'
      render :update do |page|
        page.insert_html :bottom, 'comments', :partial => 'comment'
        page[:comment_comment].clear
        flash.keep(:post_id)
        page["comment_#{@comment.id}"].visual_effect :highlight,
          :duration => 3.5    
      end 
    end
  end  
  
  def trash_comment
    comment_id = params[:comment]
    Comment.delete(comment_id)
    
    render :update do |page|
      page.replace_html "comment_#{comment_id}", "" 
    end          
  end
  
  
end
