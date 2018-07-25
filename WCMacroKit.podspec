#
#  Be sure to run `pod spec lint WCMacroKit.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "WCMacroKit"
  s.version      = "0.0.1"
  s.summary      = "A collection macro definitions for coding."
  s.description  = <<-DESC
  WCMacroKit provides utility macros, such as strings, colors, versions and so on.
                   DESC

  s.homepage     = "https://github.com/daydreamboy/WCMacroKit"
  s.license      = "MIT"

  s.author       = { "daydreamboy" => "wesley4chen@gmail.com" }
  s.source       = { :git => "https://github.com/daydreamboy/WCMacroKit.git", :tag => "#{s.version}" }
  s.vendored_frameworks = "Build/Product/WCMacroKit.framework"
  s.prepare_command = '/bin/bash prepare_command_build.sh'
end
