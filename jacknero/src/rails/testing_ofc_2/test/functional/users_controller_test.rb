require 'test_helper'

class UsersControllerTest < ActionController::TestCase
  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:users)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create users" do
    assert_difference('Users.count') do
      post :create, :users => { }
    end

    assert_redirected_to users_path(assigns(:users))
  end

  test "should show users" do
    get :show, :id => users(:one).id
    assert_response :success
  end

  test "should get edit" do
    get :edit, :id => users(:one).id
    assert_response :success
  end

  test "should update users" do
    put :update, :id => users(:one).id, :users => { }
    assert_redirected_to users_path(assigns(:users))
  end

  test "should destroy users" do
    assert_difference('Users.count', -1) do
      delete :destroy, :id => users(:one).id
    end

    assert_redirected_to users_path
  end
end
