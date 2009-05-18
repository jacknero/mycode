class MailerQuestion < Iso2022jpMailer
  def notify_create(question, email)
    recipients email
    from 'kyoso_km@ecl.info.kindai.ac.jp'
    subject base64('新しい質問が追加されました')
    body "新しい質問が追加されました     http://ecl.info.kindai.ac.jp/kyoso_km"
  end
  
  def notify_create_answer(question, email)
    recipients email
    from 'kyoso_km@ecl.info.kindai.ac.jp'
    subject base64('新しい回答が追加されました')
    body "新しい回答が追加されました     http://ecl.info.kindai.ac.jp/kyoso_km"
  end
  
  def notify_required_answer(question, email)
    recipients email
    from 'kyoso_km@ecl.info.kindai.ac.jp'
    subject base64('回答をお願いします')
    body "回答をお願いします     http://ecl.info.kindai.ac.jp/kyoso_km"
  end
  
  def notify_create_answer_in_resolved(question, email)
    recipients email
    from 'kyoso_km@ecl.info.kindai.ac.jp'
    subject base64('解決済みの質問に回答が入りました')
    body "解決済みの質問に回答が入りました     http://ecl.info.kindai.ac.jp/kyoso_km"
  end
  
  def base64(text, charset="iso-2022-jp", convert=true)
    if convert
      if charset == "iso-2022-jp"
        text = NKF.nkf('-j -m0', text)
      end
    end
    text = [text].pack('m').delete("\r\n")
         "=?#{charset}?B?#{text}?="
  end
end
