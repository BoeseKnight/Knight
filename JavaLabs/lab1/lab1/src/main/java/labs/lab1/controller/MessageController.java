package labs.lab1.controller;

import labs.lab1.Parity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/result")
public class MessageController {
    @GetMapping
    public Parity parity(@RequestParam(value="num", defaultValue="1") int num){
        return new Parity(num);
    }
}
