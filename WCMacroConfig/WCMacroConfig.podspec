Pod::Spec.new do |s|
  s.name         = "WCMacroConfig"
  s.version      = "0.0.1"
  s.summary      = "A collection macro definitions for coding."
  s.description  = <<-DESC
  WCMacroConfig provides utility macros, such as strings, colors, versions and so on.
                   DESC
  s.homepage     = "https://github.com/daydreamboy/WCMacroKit"
  s.license      = "MIT"
  s.author       = { "daydreamboy" => "wesley4chen@gmail.com" }
  s.source       = { :git => "https://github.com/daydreamboy/WCMacroKit.git", :tag => "#{s.version}" }
  s.ios.deployment_target = '11.0'
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
end
