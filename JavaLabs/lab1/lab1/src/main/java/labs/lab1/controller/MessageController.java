package labs.lab1.controller;

import labs.lab1.Parity;
import labs.lab1.exception.RequestException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/result")
public class MessageController {
    @GetMapping
    public Parity parity(@RequestParam(value = "num", defaultValue = "1") String num) {
        try {
            int number = Integer.parseInt(num);
            return new Parity(number);
        }
        catch(NumberFormatException nfe) {
            throw new RequestException("OOPS");
        }
    }
}
